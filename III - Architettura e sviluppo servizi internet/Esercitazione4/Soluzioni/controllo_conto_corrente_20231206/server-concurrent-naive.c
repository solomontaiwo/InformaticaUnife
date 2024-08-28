#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define N 256

/* Gestore del segnale SIGCHLD */
void handler(int signo)
{
        int status;

	(void)signo;

        /* gestisco tutti i figli terminati */
        while (waitpid(-1, &status, WNOHANG) > 0)
		continue;
}

int main(int argc, char** argv)
{
        struct addrinfo hints, *res;
        int err, sd, ns, pid, pid2, on, piped[2];
        char categoria[N];
        struct sigaction sa;

        /* Controllo argomenti */
        if (argc < 2){
                printf("Uso: ./server <porta> \n");
                exit(EXIT_FAILURE);
        }

	/* Ignoro SIGPIPE */
	signal(SIGPIPE, SIG_IGN);

	/* Installo gestore SIGCHLD usando la syscall sigaction, che è uno
	 * standard POSIX, al posto di signal che ha semantiche diverse a
	 * seconda del sistema operativo */
        sigemptyset(&sa.sa_mask);
        /* uso SA_RESTART per evitare di dover controllare esplicitamente se
         * accept è stata interrotta da un segnale e in tal caso rilanciarla
         * (si veda il paragrafo 21.5 del testo M. Kerrisk, "The Linux
         * Programming Interface") */
        sa.sa_flags   = SA_RESTART;
        sa.sa_handler = handler;

        if (sigaction(SIGCHLD, &sa, NULL) == -1) {
                perror("sigaction");
                exit(EXIT_FAILURE);
        }

        memset(&hints, 0, sizeof(hints));
        hints.ai_family   = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags    = AI_PASSIVE;

        if ((err = getaddrinfo(NULL, argv[1], &hints, &res)) != 0) {
                fprintf(stderr, "Errore setup indirizzo bind: %s\n", gai_strerror(err));
                exit(EXIT_FAILURE);
        }

        if ((sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0){
                perror("Errore in socket");
                exit(EXIT_FAILURE);
        }

        on = 1;
        if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))<0){
                perror("setsockopt");
                exit(EXIT_FAILURE);
        }

        if (bind(sd, res->ai_addr, res->ai_addrlen) < 0) {
                perror("Errore in bind");
                exit(EXIT_FAILURE);
        }

        freeaddrinfo(res);

        if (listen(sd, SOMAXCONN) < 0){
                perror("listen");
                exit(EXIT_FAILURE);
        }

        /* Attendo i client... */
        for (;;) {
                printf("Server in ascolto...\n");

                if ((ns = accept(sd, NULL, NULL)) < 0) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                }

                /* Generazione di un figlio */
                if ((pid = fork())<0){
                        perror("fork");
                        exit(EXIT_FAILURE);
                } else if (pid == 0){ /* figlio */

                        /* Chiudo la socket passiva */
                        close(sd);

                        memset(categoria, 0, sizeof(categoria));
                        if (read(ns, categoria, sizeof(categoria)-1) < 0) {
                                perror("read categoria");
                                exit(EXIT_FAILURE);
                        }

                        if (pipe(piped) < 0) {
                                perror("pipe");
                                exit(EXIT_FAILURE);
                        }

                        if ((pid2 = fork()) < 0){
                                perror("seconda fork");
                                exit(EXIT_FAILURE);
                        } else if (pid2 == 0){

                                // Nipote N1
                                // Chiudo i descrittori che non servono
                                close(piped[0]);
                                close(ns);

                                // Ridireziono stdout
                                close(1);
                                if (dup(piped[1]) < 0) {
					perror("dup");
					exit(EXIT_FAILURE);
				}
                                close(piped[1]);

                                // Eseguo la grep mandando i risultati al figlio
                                /* uso "test.txt" al posto di "/var/local/conto_corrente.txt" */
                                execlp("grep", "grep", categoria, "test.txt", (char*)NULL); 
                                perror("execlp grep");
                                exit(EXIT_FAILURE);
                        }

                        /* figlio */

                        /* Chiudo descrittori non necessari */
                        close(piped[1]);

                        /* Ridireziono stdin */
                        close(0);
			if (dup(piped[0]) < 0) {
				perror("dup");
				exit(EXIT_FAILURE);
			}
                        close(piped[0]);

                        /* Ridireziono stdout */
                        close(1);
			if (dup(ns) < 0) {
				perror("dup");
				exit(EXIT_FAILURE);
			}
                        close(ns);

                        execlp("sort", "sort", "-r", "-n", (char*)NULL);
                        perror("execlp sort");
                        exit(EXIT_FAILURE);
                }

                /* padre */
                close(ns);
        }

        return 0;
}

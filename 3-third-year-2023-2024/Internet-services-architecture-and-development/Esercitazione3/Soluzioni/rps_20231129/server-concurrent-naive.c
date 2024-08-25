#define _POSIX_C_SOURCE	200809L
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


/* Gestore del segnale SIGCHLD */
void handler(int signo)
{
        int status;

	(void)signo;

        /* gestisco tutti i figli terminati */
        while (waitpid(-1, &status, WNOHANG) > 0)
		continue;
}


int main(int argc, char **argv)
{
        struct addrinfo hints, *res;
        int err, sd, ns, pid, on;
        char option[1024];
        struct sigaction sa;

        /* Controllo argomenti */
        if (argc != 2) {
                fprintf(stderr, "Uso: %s porta\n", argv[0]);
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
        /* Usa AF_INET per forzare solo IPv4, AF_INET6 per forzare solo IPv6 */
        hints.ai_family   = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags    = AI_PASSIVE;

        if ((err = getaddrinfo(NULL, argv[1], &hints, &res)) != 0) {
                fprintf(stderr, "Errore setup indirizzo bind: %s\n", gai_strerror(err));
                exit(EXIT_FAILURE);
        }

        if ((sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0) {
                perror("Errore in socket");
                exit(EXIT_FAILURE);
        }

        on = 1;
        if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) {
                perror("setsockopt");
                exit(EXIT_FAILURE);
        }

        if (bind(sd, res->ai_addr, res->ai_addrlen) < 0) {
                perror("Errore in bind");
                exit(EXIT_FAILURE);
        }

        freeaddrinfo(res);

        if (listen(sd, SOMAXCONN)<0){
                perror("listen");
                exit(EXIT_FAILURE);
        }

        /* Attendo i client... */
        for (;;){
                printf("Server in ascolto...\n");

                if ((ns = accept(sd, NULL, NULL)) < 0) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                }

                /* Generazione di un figlio */
                if ((pid = fork()) < 0) {
                        perror("fork");
                        exit(EXIT_FAILURE);
                } else if (pid == 0) {
                        /* figlio */
                        close(sd);

                        /* Leggo option  */
                        /* Inizializzo il buffer a zero e leggo sizeof(buff)-1
                         * byte, così sono sicuro che il contenuto del buffer
                         * sarà sempre null-terminated. In questo modo, posso
                         * interpretarlo come una stringa C e passarlo
                         * direttamente alla funzione exec. */
                        memset(option, 0, sizeof(option));
                        if (read(ns, option, sizeof(option)-1) < 0){
                                perror("read option");
                                exit(EXIT_FAILURE);
                        }

                        /* ridireziono stdout e stderr */
                        close(1);
                        if (dup(ns) < 0) {
                                perror("dup");
                                exit(EXIT_FAILURE);
                        }
                        close(ns);

                        /* Eseguo il ps sul server con i parametri corretti */
                        if (strlen(option) == 0) {
                                execlp("ps", "ps", (char*)NULL);
                                perror("exec ps 1");
                                exit(EXIT_FAILURE);
                        } else {
                                execlp("ps", "ps", option, (char*)NULL);
                                perror("exec ps 2");
                                exit(EXIT_FAILURE);
                        }
                } else {
                        /* padre */
                        close(ns);
                }
        }

        close(sd);

        return 0;
}

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
#ifdef USE_LIBUNISTRING
#  include <unistr.h> /* per libunistring */
#endif

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
        int err, sd, ns, pid, on, file, nread;
        char nomeFile[N], stringa[N];
        char *ack="ack\n";
        struct sigaction sa;

        /* Controllo argomenti */
        if (argc < 2) {
                printf("Uso: ./server-concurrent-naive <porta> \n");
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
        for(;;){
                printf("Server in ascolto...\n");

                if ((ns = accept(sd, NULL, NULL)) < 0) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                }

                /* Generazione di un figlio */
                if ((pid = fork())<0){
                        perror("fork");
                        exit(EXIT_FAILURE);
                } else if (pid == 0){
                        /* FIGLIO */

			/* Chiudo socket passiva. */
                        close(sd);

                        /* Inizializzo il buffer a zero e leggo sizeof(nomeFile)-1
                         * byte, così sono sicuro che il contenuto del buffer
                         * sarà sempre null-terminated. In questo modo, posso
                         * interpretarlo come una stringa C e passarlo
                         * successivamente alle funzioni open ed execlp. */
                        memset(nomeFile, 0, sizeof(nomeFile));
                        if ((nread = read(ns, nomeFile, N-1)) < 0){
                                perror("read nomeFile");
                                exit(EXIT_FAILURE);
                        }

#ifdef USE_LIBUNISTRING
			/* Verifico che il messaggio sia UTF-8 valido */
			if (u8_check((uint8_t *)nomeFile, nread) != NULL) {
				/* Client che malfunziona - inviato messaggio
				 * con stringa UTF-8 non valida */
				fprintf(stderr, "Request is not valid UTF-8!\n");
				close(ns);
				exit(EXIT_SUCCESS);
			}
#endif

                        if ((file = open(nomeFile, O_RDONLY)) < 0) {
                                //non trovo il file, termino il programma
                                close(ns);
                                exit(EXIT_FAILURE);
                        } else {
                                close(file);
                        }

                        if (write(ns, ack, strlen(ack)) < 0){
                                perror("scrivo ack");
                                exit(EXIT_FAILURE);
                        }

                        /* Inizializzo il buffer a zero e leggo sizeof(stringa)-1
                         * byte, così sono sicuro che il contenuto del buffer
                         * sarà sempre null-terminated. In questo modo, posso
                         * interpretarlo come una stringa C e passarlo
                         * successivamente alla funzione execlp. */
                        memset(stringa, 0, sizeof(stringa));
                        if ((nread = read(ns, stringa, sizeof(stringa)-1)) < 0){
                                perror("read stringa");
                                exit(EXIT_FAILURE);
                        }

#ifdef USE_LIBUNISTRING
			/* Verifico che il messaggio sia UTF-8 valido */
			if (u8_check((uint8_t *)stringa, nread) != NULL) {
				/* Client che malfunziona - inviato messaggio
				 * con stringa UTF-8 non valida */
				fprintf(stderr, "Request is not valid UTF-8!\n");
				close(ns);
				exit(EXIT_SUCCESS);
			}
#endif

                        /* Ridireziono stdout e stderr */
                        close(1);
                        close(2);
                        dup(ns);
                        dup(ns);
                        close(ns);

                        /* Eseguo la grep sul server con i parametri corretti */
                        execlp("grep", "grep", stringa, nomeFile, (char*)NULL);
                        perror("exec grep");
                        exit(EXIT_FAILURE);
                } else {
                        /* padre */
                        close(ns);
                }
        }

        close(sd);

        return 0;
}

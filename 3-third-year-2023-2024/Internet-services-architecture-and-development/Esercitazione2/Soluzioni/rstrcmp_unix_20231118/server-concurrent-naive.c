#define _POSIX_C_SOURCE 200809L
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/* Gestore del segnale SIGCHLD */
void handler(int signo)
{
        int status;

        (void)signo; /* per evitare warning */

        /* eseguo wait non bloccanti finché ho dei figli terminati */
        while (waitpid(-1, &status, WNOHANG) > 0)
                continue;
}


int main(int argc, char **argv)
{
        int sd, err, on;
        struct addrinfo hints, *res;
        struct sigaction sa;

	/* Controllo argomenti */
        if (argc != 2) {
                fprintf(stderr, "Sintassi: %s porta\n", argv[0]);
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

	/* Preparo direttive getaddrinfo */
        memset(&hints, 0, sizeof(hints));
        /* Usa AF_INET per forzare solo IPv4, AF_INET6 per forzare solo IPv6 */
        hints.ai_family   = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags    = AI_PASSIVE;

	/* Uso getaddrinfo per preparare le strutture dati da usare con socket e bind */
        if ((err = getaddrinfo(NULL, argv[1], &hints, &res)) != 0) {
                fprintf(stderr, "Errore setup indirizzo bind: %s\n", gai_strerror(err));
                exit(EXIT_FAILURE);
        }

	/* Creo la socket */
        if ((sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0){
                perror("Errore in socket");
                exit(EXIT_FAILURE);
        }

	/* Disabilo attesa uscita fase TIME_WAIT prima di creazioe socket */
        on = 1;
        if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0){
                perror("setsockopt");
                exit(EXIT_FAILURE);
        }

	/* Metto in ascolto la socket sulla porta desiderata */
        if (bind(sd, res->ai_addr, res->ai_addrlen) < 0) {
                perror("Errore in bind");
                exit(EXIT_FAILURE);
        }

        /* A questo punto, posso liberare la memoria allocata da getaddrinfo */
        freeaddrinfo(res);

        /* Trasforma in socket passiva d'ascolto */
        if (listen(sd, SOMAXCONN) < 0) {
                perror("listen");
                exit(EXIT_FAILURE);
        }

        for(;;) {
                int ns, pid, nread;

		/* Mi metto in attesa di richieste di connessione */
                if ((ns = accept(sd, NULL, NULL)) < 0) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                }

		/* Creo un processo figlio per gestire la richiesta */
                if ((pid = fork()) < 0) {
                        perror("fork");
                        exit(EXIT_FAILURE);
                } else if (pid == 0) { /* FIGLIO */
                        char str1[4096], str2[4096], response[80];
                        const char *ack = "ACK";

                        /* Chiudo la socket passiva */
                        close(sd);

                        /* Inizializzo il buffer a zero e leggo sizeof(str1)-1
                         * byte, così sono sicuro che il contenuto del buffer
                         * sarà sempre null-terminated. In questo modo, posso
                         * interpretarlo come una stringa C e passarlo
                         * direttamente alla funzione strcmp. */
                        memset(str1, 0, sizeof(str1));
                        if ((nread = read(ns, str1, sizeof(str1)-1)) < 0) {
                                perror("read");
                                exit(EXIT_FAILURE);
                        }

                        /* Invio ACK al Client */
                        if (write(ns, ack, strlen(ack)) < 0) {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }

                        /* Inizializzo il buffer a zero e leggo sizeof(str2)-1
                         * byte, così sono sicuro che il contenuto del buffer
                         * sarà sempre null-terminated. In questo modo, posso
                         * interpretarlo come una stringa C e passarlo
                         * direttamente alla funzione strcmp. */
                        memset(str2, 0, sizeof(str2));
                        if ((nread = read(ns, str2, sizeof(str2)-1)) < 0) {
                                perror("read");
                                exit(EXIT_FAILURE);
                        }

                        /* Preparo il buffer contenente la risposta */
                        if (strcmp(str1, str2) == 0) {
                                /* Le stringhe sono identiche */
                                strncpy(response, "SI", sizeof(response));
                        } else {
                                /* Le stringhe sono diverse */
                                strncpy(response, "NO", sizeof(response));
			}

                        /* Invio la risposta */
                        if (write(ns, response, strlen(response)) < 0) {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }

                        /* Chiudo la socket attiva */
                        close(ns);

                        /* Termino il figlio */
                        exit(EXIT_SUCCESS);
                }

                /* PADRE */

                /* Chiudo la socket attiva */
                close(ns);
        }

        close(sd);

        return 0;
}


#define _POSIX_C_SOURCE 200809L
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv)
{
        int sd, err, on;
        struct addrinfo hints, *res;

	/* Controllo argomenti */
        if (argc != 2) {
                fprintf(stderr, "Sintassi: %s porta\n", argv[0]);
                exit(EXIT_FAILURE);
        }

        /* Ignoro SIGPIPE */
	signal(SIGPIPE, SIG_IGN);

	/* Preparo direttive getaddrinfo */
        memset(&hints, 0 ,sizeof(hints));
        /* Usa AF_INET per forzare solo IPv4, AF_INET6 per forzare solo IPv6 */
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;

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

	/* Ciclo gestione richieste - server iterativo con connessione transiente */
        for (;;) {
		char request[4096], response[256];
                int ns, nread, length_of_string;

		/* Mi metto in attesa di richieste di connessione */
                ns = accept(sd, NULL, NULL);
                if (ns < 0) {
			/* Non ho installato gestore SIGCHLD con SA_RESTART,
			 * quindi devo controllare e gestire esplicitamente il
			 * caso EINTR */
                        if (errno == EINTR)
                                continue;
                        perror("accept");
                        exit(EXIT_FAILURE);
                }

		/* Inizializzo il buffer request a zero e non uso l'ultimo
		 * byte, così sono sicuro che il contenuto del buffer sarà
		 * sempre null-terminated. In questo modo, posso interpretarlo
		 * come una stringa C e passarlo direttamente alla funzione
		 * strlen. Questa è un'operazione che va svolta prima di ogni
		 * nuova richiesta. */
                memset(request, 0, sizeof(request));

		/* Leggo richiesta da Client */
                if ((nread = read(ns, request, sizeof(request)-1)) < 0){
                        perror("read");
                        close(ns);
                        continue;
                }

		/* Calcolo numero byte contenuti in stringa richiesta */
		length_of_string = strlen(request);

		/* Preparo il buffer contenente la risposta */
		snprintf(response, sizeof(response), "%d\n", length_of_string);

		/* Invio la risposta */
                if (write(ns, response, strlen(response)) < 0){
                        perror("write");
                        close(ns);
                        continue;
                }

		/* Chiudo la socket attiva */
		close(ns);
        }

	/* Chiudo la socket passiva (just in case) */
        close(sd);

        return 0;
}

#define _POSIX_C_SOURCE 200809L
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
        char buff[2048];
        int sd, err, nread;
        struct addrinfo hints, *ptr, *res;

        if (argc != 5) {
                fprintf(stderr, "Sintassi: rstrcmp hostname porta stringa1 stringa2\n");
                exit(EXIT_FAILURE);
        }

	/* ignoro SIGPIPE */
	signal(SIGPIPE, SIG_IGN);

        memset(&hints, 0, sizeof(hints));
        hints.ai_family   = AF_INET;
        hints.ai_socktype = SOCK_STREAM;

        err = getaddrinfo(argv[1], argv[2], &hints, &res);
        if (err != 0) {
                fprintf(stderr, "Errore risoluzione nome: %s\n", gai_strerror(err));
                exit(EXIT_FAILURE);
        }

        /* connessione con fallback */
        for (ptr=res; ptr != NULL; ptr=ptr->ai_next) {
                sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
                /* se la socket fallisce, passo all'indirizzo successivo */
                if (sd < 0)
                        continue;

                /* se la connect va a buon fine, esco dal ciclo */
                if (connect(sd, ptr->ai_addr, ptr->ai_addrlen) == 0)
                        break;

                /* altrimenti, chiudo la socket e passo all'indirizzo
                 * successivo */
                close(sd);
        }

        /* controllo che effettivamente il client sia connesso */
        if (ptr == NULL) {
                fprintf(stderr, "Errore di connessione!\n");
                exit(EXIT_FAILURE);
        }

        /* a questo punto, posso liberare la memoria allocata da getaddrinfo */
        freeaddrinfo(res);

        /* Invio la prima stringa. Non mando il terminatore - dovrò quindi fare
         * attenzione lato server. */
        if (write(sd, argv[3], strlen(argv[3])) < 0) {
                perror("write");
                exit(EXIT_FAILURE);
        }

        /* Attendo un ACK dal Server */
        if (read(sd, buff, sizeof(buff)) < 0) {
                perror("read");
                exit(EXIT_FAILURE);
        }

        /* Invio la seconda stringa. Non mando il terminatore - dovrò quindi fare
         * attenzione lato Server. */
        if (write(sd, argv[4], strlen(argv[4])) < 0) {
                perror("write");
                exit(EXIT_FAILURE);
        }

        /* Ricezione risultato */
        while ((nread = read(sd, buff, sizeof(buff))) > 0) {
                if (write(1, buff, nread) < 0) {
                        perror("write su stdout");
                        exit(EXIT_FAILURE);
                }
        }

        /* Controllo errori di lettura */
        if (nread < 0) {
                perror("read del risultato");
                exit(EXIT_FAILURE);
        }

        /* stampo un \n prima di terminare */
        if (write(1, "\n", 1) < 0) {
                perror("write");
                exit(EXIT_FAILURE);
        }

        /* chiudo la socket */
        close(sd);

        return 0;
}


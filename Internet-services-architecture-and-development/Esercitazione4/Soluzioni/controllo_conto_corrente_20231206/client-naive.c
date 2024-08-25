#define _POSIX_C_SOURCE 200809L
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define DIM 4096

int main(int argc, char** argv) {
        int err;
        struct addrinfo hints;
        struct addrinfo *res,*ptr;
        char *host_remoto;
        char *servizio_remoto;
        int sd, nread;
        char buf[DIM], categoria[DIM];
        int i = 1;

        /* Controllo argomenti */
        if (argc < 3) {
                printf("Uso: controllo_conto_corrente <server> <porta>\n");
                exit(EXIT_FAILURE);
        }

	/* Ignoro SIGPIPE */
	signal(SIGPIPE, SIG_IGN);

        /* Costruzione dell'indirizzo */
        memset(&hints, 0, sizeof(hints));
        hints.ai_family   = AF_INET;
        hints.ai_socktype = SOCK_STREAM;

        /* Risoluzione dell'host */
        host_remoto = argv[1];
        servizio_remoto = argv[2];

        if ((err = getaddrinfo(host_remoto, servizio_remoto, &hints, &res)) != 0) {
                fprintf(stderr, "Errore risoluzione nome: %s\n", gai_strerror(err));
                exit(EXIT_FAILURE);
        }

        for(;;) {
                /* Lettura dati dall'utente */
                printf("Inserisci la categoria di spese cui sei interessato ('fine' per uscire):\n");
                if (scanf("%s", categoria) == EOF || errno != 0) {
                        perror("scanf");
                        exit(EXIT_FAILURE);
                }

                if (strcmp(categoria, "fine") == 0) {
                        printf("Hai scelto di terminare il programma.\n");
                        break;
                }

                for (ptr = res; ptr != NULL; ptr = ptr->ai_next) {
                        /* se socket fallisce salto direttamente alla prossima iterazione */
                        if ((sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol)) < 0) {
                                fprintf(stderr, "creazione socket fallita\n");
                                continue;
                        }
                        /* se connect funziona esco dal ciclo */
                        if (connect(sd, ptr->ai_addr, ptr->ai_addrlen) == 0) {
                                printf("connect riuscita al tentativo %d\n", i);
                                break;
                        }
                        i++;
                        close(sd);
                }

                /* Verifica sul risultato restituito da getaddrinfo */
                if (ptr == NULL) {
                        fprintf(stderr, "Errore risoluzione nome: nessun indirizzo corrispondente trovato\n");
                        exit(EXIT_FAILURE);
                }

                /* Mando il nome della categoria al server */
                if (write(sd, categoria, strlen(categoria)) < 0) {
                        perror("write categoria");
                        exit(EXIT_FAILURE);
                }

                /* Ricezione risultato */

                /* È consigliabile effettuare il flushing del buffer di printf
                 * prima di iniziare a scrivere sullo standard output con write */
                fflush(stdout);

                while ((nread = read(sd, buf, DIM)) > 0) {
                        if (write(1, buf, nread) < 0) {
                                perror("write su stdout");
                                exit(EXIT_FAILURE);
                        }
                }

                /* Controllo errori di lettura */
                if (nread < 0) {
                        perror("read del risultato");
                        exit(EXIT_FAILURE);
                }

                /* ricordarsi sempre di chiudere la socket */
                close(sd);
        }

        /* Liberiamo la memoria allocata da getaddrinfo() */
        freeaddrinfo(res);

        return 0;
}

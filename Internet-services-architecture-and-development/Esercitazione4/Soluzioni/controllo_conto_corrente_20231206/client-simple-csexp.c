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
#include "rxb.h"
#include "utils.h"
#include "simple_csexp.h"

#define DIM 1024

int main(int argc, char** argv) {
        int err, sd = -1, i = 1;
        struct addrinfo hints, *res, *ptr;
        char *host_remoto, *servizio_remoto;
        char categoria[DIM];
	rxb_t rxb;

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

        /* Liberiamo la memoria allocata da getaddrinfo() */
        freeaddrinfo(res);

        rxb_init(&rxb, 64 * 1024);

        for(;;) {
		int cc;
                char request[4096];
		char **strings;
		size_t strings_len;

                /* Lettura dati dall'utente */
                printf("Inserisci la categoria di spese a cui sei interessato ('fine' per uscire):\n");
                if (scanf("%s", categoria) == EOF || errno != 0) {
                        perror("scanf");
                        exit(EXIT_FAILURE);
                }

                if (strcmp(categoria, "fine") == 0) {
                        printf("Hai scelto di terminare il programma.\n");
                        break;
                }

                snprintf(request, sizeof(request), "(%ld:%s)", strlen(categoria), categoria);

                /* Mando il nome della categoria al server */
                if (write_all(sd, request, strlen(request)) < 0) {
                        perror("write categoria");
                        exit(EXIT_FAILURE);
                }

		/* Leggo messaggio risposta da Server */
		strings = NULL; strings_len = 0;
		cc = simple_csexp_read_message(&rxb, sd, &strings, &strings_len);
		if (cc < 0) {
			fprintf(stderr, "Errore lettura messaggio da socket!\n");
			exit(EXIT_FAILURE);
		}

                /* simple_csexp_read_message alloca memoria, che devo liberare
                 * manualmente quando non mi serve più. (In realtà il messaggio
                 * dovrebbe avere solo una stringa, ma faccio comunque un
                 * ciclo.) */
                for (i = 0; i < strings_len; ++i) {
			/* Stampo stringa a video */
			puts(strings[i]);

			free(strings[i]);
		}
                free(strings);
        }

        /* ricordarsi sempre di chiudere la socket */
        close(sd);

        return 0;
}

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "rxb.h"
#include "utils.h"
#ifdef USE_LIBUNISTRING
#include <unistring.h>
#endif /* USE_LIBUNISTRING */

#define MAX_RESPONSE_SIZE (16 * 1024)


/* leggi_dati_sensori hostname porta */
/* argv[0]            argv[1]  argv[2] */
int main(int argc, char *argv[])
{
	rxb_t rxb;
	int err, sd;
	struct addrinfo hints, *res, *ptr;

	/* Controllo errori */
	if (argc != 3) {
		fprintf(stderr, "Error! Usage:\n\t%s hostname porta\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* Ripristiniamo semantica sensata pipe e socket */
	signal(SIGPIPE, SIG_IGN);

	/* Preparo chiamata getaddrinfo */
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	char *hostname = argv[1];
	char *service = argv[2];

	err = getaddrinfo(hostname, service, &hints, &res);
	if (err != 0) {
		fprintf(stderr, "Errore getaddrinfo: %s\n", gai_strerror(err));
		exit(EXIT_FAILURE);
	}

	/* Procedura di connessione con fallback */
	for (ptr = res; ptr != NULL; ptr = ptr->ai_next) {
		sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (sd < 0)
			continue;

		err = connect(sd, ptr->ai_addr, ptr->ai_addrlen);
		if (err == 0) 
			break;

		close(sd);
	}

	if (ptr == NULL) {
		fprintf(stderr, "Errore di connessione!\n");
		exit(EXIT_FAILURE);
	}
	
	/* Libero memoria allocata da getaddrinfo */
	freeaddrinfo(res);

	/* Alloco buffer rxb */
	rxb_init(&rxb, MAX_RESPONSE_SIZE * 2);

	/* Ciclo di richieste di servizio */
	for(;;) {
		char tipo_sensore[4096];
		char stanza_sensore[4096];
		char numero_letture[4096];

		puts("Inserisci tipo sensore (fine per terminare):");
		if (fgets(tipo_sensore, sizeof(tipo_sensore), stdin) == NULL) {
			fprintf(stderr, "Errore fgets tipo_sensore\n");
			exit(EXIT_FAILURE);
		}

		if (strcmp(tipo_sensore, "fine\n") == 0) {
			break;
		}

		puts("Inserisci stanza sensore (fine per terminare):");
		if (fgets(stanza_sensore, sizeof(stanza_sensore), stdin) == NULL) {
			fprintf(stderr, "Errore fgets stanza_sensore\n");
			exit(EXIT_FAILURE);
		}

		if (strcmp(stanza_sensore, "fine\n") == 0) {
			break;
		}

		puts("Inserisci numero letture (fine per terminare):");
		if (fgets(numero_letture, sizeof(numero_letture), stdin) == NULL) {
			fprintf(stderr, "Errore fgets numero_letture\n");
			exit(EXIT_FAILURE);
		}

		if (strcmp(numero_letture, "fine\n") == 0) {
			break;
		}

		err = write_all(sd, tipo_sensore, strlen(tipo_sensore));
		if (err < 0) {
			perror("write_all tipo_sensore");
			exit(EXIT_FAILURE);
		}
		
		err = write_all(sd, stanza_sensore, strlen(stanza_sensore));
		if (err < 0) {
			perror("write_all stanza_sensore");
			exit(EXIT_FAILURE);
		}

		err = write_all(sd, numero_letture, strlen(numero_letture));
		if (err < 0) {
			perror("write_all numero_letture");
			exit(EXIT_FAILURE);
		}

		/* Leggo risposta del server */
		while(1) {
			char line[4096];
			size_t line_len;

			/* Leggo riga di testo dal Server */
			memset(line, 0, sizeof(line));
			line_len = sizeof(line) - 1;
			err = rxb_readline(&rxb, sd, line, &line_len);
			if (err < 0) {
				perror("Errore rxb_readline");
				exit(EXIT_FAILURE);
			}

#ifdef USE_LIBUNISTRING
			if (u8_check((uint8_t *)line, line_len) != NULL) {
				fputs("Errore: testo UTF-8 non valido!", stderr);
				exit(EXIT_FAILURE);
			}
#endif /* USE_LIBUNISTRING */

			/* Esco in caso di riga di fine risposta */
			if (strcmp(line, "--- END RESPONSE ---") == 0)
				break;

			/* Stampo riga a video */
			puts(line);
		}
	}

	/* Libero buffer rxb */
	rxb_destroy(&rxb);

	/* Chiudo la socket */
	close(sd);

	return 0;
}

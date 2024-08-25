#define _POSIX_C_SOURCE 200809L
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
        int sd,err,nread;
        struct addrinfo hints, *res, *ptr;
        char line[4096], len[2048];

	/* Controllo argomenti */
        if (argc != 3) {
                fprintf(stderr, "Sintassi: %s hostname porta\n", argv[0]);
                exit(EXIT_FAILURE);
        }

        /* Ignoro SIGPIPE */
	signal(SIGPIPE, SIG_IGN);

        /* Preparo direttive getaddrinfo */
        memset(&hints,0,sizeof(hints));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;

        /* Invoco getaddrinfo */
        err = getaddrinfo(argv[1], argv[2], &hints, &res);
        if(err != 0){
                fprintf(stderr, "Errore risoluzione nome: %s\n", gai_strerror(err));
                exit(2);
        }

	/* Leggo una stringa */
        printf("Inserisci stringa:\n");
	if (fgets(line, sizeof(line), stdin) == NULL) {
		perror("fgets");
		exit(EXIT_FAILURE);
	}

        /* fgets inserisce nel buffer anche il \n, quindi lo tolgo, 
        inserendo al suo posto un byte null (terminatore di stringa \0) */
        line[strlen(line) - 1] = '\0';

        while (strcmp(line, "fine") != 0) {
		/* Connessione con fallback */
		for (ptr=res; ptr != NULL; ptr=ptr->ai_next) {
			sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
			/* Se la socket fallisce, passo all'indirizzo successivo */
			if (sd < 0) continue;

			/* Se la connect va a buon fine, esco dal ciclo */
			if (connect(sd, ptr->ai_addr, ptr->ai_addrlen) == 0)
				break;

			/* Altrimenti, chiudo la socket e passo all'indirizzo
			 * successivo */
			close(sd);
		}

		/* Controllo che effettivamente il client sia connesso */
		if (ptr == NULL) {
			fprintf(stderr, "Errore di connessione!\n");
			exit(EXIT_FAILURE);
		}

                /* Invio la richiesta */
                if (write(sd, line, strlen(line)) < 0){
                        perror("write");
                        exit(EXIT_FAILURE);
                }

                /* Leggo la risposta e la stampo a video */
                memset(len, 0, sizeof(len));
                nread = read(sd, len, sizeof(len)-1);
                if (nread < 0){
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                printf("Num. caratteri stringa inserita: %s\n", len);

                /* Chiudo la socket */
                close(sd);

		/* Leggo una nuova stringa */
		printf("Inserisci stringa:\n");
		if (fgets(line, sizeof(line), stdin) == NULL) {
			perror("fgets");
			exit(EXIT_FAILURE);
		}
                
                /* fgets inserisce nel buffer anche il \n, quindi lo tolgo, 
                inserendo al suo posto un byte null (terminatore di stringa) */
                line[strlen(line) - 1] = '\0';
        }

        /* A questo punto, posso liberare la memoria allocata da getaddrinfo */
        freeaddrinfo(res);

        return 0;
}

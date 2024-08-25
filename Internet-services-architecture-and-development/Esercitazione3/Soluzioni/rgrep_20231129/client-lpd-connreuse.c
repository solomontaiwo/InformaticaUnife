#define _POSIX_C_SOURCE 200809L
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "utils.h"


int main(int argc, char **argv)
{
        uint8_t buffer[2048], len[2];
        char filename[512], stringa[512];
        int filename_len, stringa_len;
        int sd, err, nread;
        struct addrinfo hints, *ptr, *res;

        if (argc != 3) {
                fprintf(stderr, "Sintassi: largest_expenses server porta\n");
                exit(EXIT_FAILURE);
        }

	/* Ignoro SIGPIPE */
	signal(SIGPIPE, SIG_IGN);

        memset(&hints, 0, sizeof(hints));
        hints.ai_family   = AF_UNSPEC;
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

        
        for (;;) {
		/* Leggo filename */
                printf("Digita il filename di interesse ('fine' per terminare):\n");
                if (scanf("%s", filename) != 1) {
                        perror("scanf");
                        exit(EXIT_FAILURE);
                }

                if (strcmp(filename, "fine") == 0) {
                        break;
                }

		/* Leggo stringa */
                printf("Digita la stringa di interesse:\n");
                if (scanf("%s", stringa) != 1) {
                        perror("scanf");
                        exit(EXIT_FAILURE);
                }

                /* Trasmetto filename */
                filename_len = strlen(filename);
                if (filename_len > UINT16_MAX) {
                        fprintf(stderr, "filename troppo grande (massimo %d byte)!\n", UINT16_MAX);
                        exit(EXIT_FAILURE);
                }

                /* Codifico lunghezza stringa1 come intero unsigned a 16 bit in formato
                 * big endian (AKA network byte order) */
                len[0] = (uint8_t)((filename_len & 0xFF00) >> 8);
                len[1] = (uint8_t)(filename_len & 0xFF);

                /* Invio lunghezza filename */
                if (write_all(sd, len, 2) < 0) {
                        perror("write");
                        exit(EXIT_FAILURE);
                }

                /* Invio filename */
                if (write_all(sd, filename, filename_len) < 0) {
                        perror("write");
                        exit(EXIT_FAILURE);
                }

                /* Trasmetto stringa */
                stringa_len = strlen(stringa);
                if (stringa_len > UINT16_MAX) {
                        fprintf(stderr, "stringa troppo grande (massimo %d byte)!\n", UINT16_MAX);
                        exit(EXIT_FAILURE);
                }

                /* Codifico lunghezza stringa1 come intero unsigned a 16 bit in formato
                 * big endian (AKA network byte order) */
                len[0] = (uint8_t)((stringa_len & 0xFF00) >> 8);
                len[1] = (uint8_t)(stringa_len & 0xFF);

                /* Invio lunghezza stringa */
                if (write_all(sd, len, 2) < 0) {
                        perror("write");
                        exit(EXIT_FAILURE);
                }

                /* Invio stringa */
                if (write_all(sd, stringa, stringa_len) < 0) {
                        perror("write");
                        exit(EXIT_FAILURE);
                }

                /* Leggo lunghezza risposta */
                if (read_all(sd, len, 2) < 0) {
                        perror("read");
                        exit(EXIT_FAILURE);
                }

                size_t risposta_len = ((size_t)len[0]) << 8 | (size_t)len[1];
                size_t to_read = risposta_len;

                /* Stampo contenuto risposta a video */
                while (to_read > 0) {
                        size_t bufsize = sizeof(buffer);
                        size_t sz = (to_read < bufsize) ? to_read : bufsize;

                        nread = read(sd, buffer, sz);
                        if (nread < 0) {
                                perror("read");
                                exit(EXIT_FAILURE);
                        }

                        if (write_all(1, buffer, nread) < 0) {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }

                        to_read -= nread;
                }

                /* Stampo un \n prima di terminare */
                if (write(1, "\n", 1) < 0) {
                        perror("write");
                        exit(EXIT_FAILURE);
                }
        }

        /* Chiudo la socket */
        close(sd);

        return 0;
}


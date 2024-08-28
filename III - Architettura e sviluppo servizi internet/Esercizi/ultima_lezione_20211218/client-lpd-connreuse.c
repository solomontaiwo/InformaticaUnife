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
#include "utils.h"


int main(int argc, char **argv)
{
        uint8_t buffer[2048];
        uint8_t len[2];
        char username[512];
        char password[512];
        int username_len;
        int password_len;
        int sd, err, nread;
        struct addrinfo hints, *ptr, *res;

        if (argc != 3) {
                fprintf(stderr, "Sintassi: %s hostname porta\n", argv[0]);
                exit(EXIT_FAILURE);
        }

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

        printf("Digita username:\n");
        if (scanf("%s", username) == EOF || errno != 0) {
                perror("scanf");
                exit(EXIT_FAILURE);
        }

        printf("Digita password:\n");
        if (scanf("%s", password) == EOF || errno != 0) {
                perror("scanf");
                exit(EXIT_FAILURE);
        }

        /* Trasmetto username */
        username_len = strlen(username);
        if (username_len > UINT16_MAX) {
                fprintf(stderr, "Username troppo grande (massimo %d byte)!\n", UINT16_MAX);
                exit(EXIT_FAILURE);
        }

        /* Codifico lunghezza stringa1 come intero unsigned a 16 bit in formato
         * big endian (AKA network byte order) */
        len[0] = (uint8_t)((username_len & 0xFF00) >> 8);
        len[1] = (uint8_t)(username_len & 0xFF);

        /* Invio lunghezza username */
	if (write_all(sd, len, 2) < 0) {
                perror("write");
                exit(EXIT_FAILURE);
        }

        /* Invio username */
	if (write_all(sd, username, username_len) < 0) {
                perror("write");
                exit(EXIT_FAILURE);
        }

        /* Trasmetto password */
        password_len = strlen(password);
        if (password_len > UINT16_MAX) {
                fprintf(stderr, "Password troppo grande (massimo %d byte)!\n", UINT16_MAX);
                exit(EXIT_FAILURE);
        }

        /* Codifico lunghezza stringa1 come intero unsigned a 16 bit in formato
         * big endian (AKA network byte order) */
        len[0] = (uint8_t)((password_len & 0xFF00) >> 8);
        len[1] = (uint8_t)(password_len & 0xFF);

        /* Invio lunghezza password */
        if (write_all(sd, len, 2) < 0) {
                perror("write");
                exit(EXIT_FAILURE);
        }

        /* Invio password */
	if (write_all(sd, password, password_len) < 0) {
                perror("write");
                exit(EXIT_FAILURE);
        }

        /*
        [ 0, 2, 'O', 'K' ]
        [ 0, 2, 'N', 'O' ]
        */

        /* Leggo ACK */
        if (read_all(sd, buffer, 4) < 0) {
                perror("read");
                exit(EXIT_FAILURE);
        }

        /* Verifico ACK */
        if (buffer[0] !=  0  || buffer[1] !=  2 ||
            buffer[2] != 'O' || buffer[3] != 'K') {
                printf("Non autorizzato!\n");
                close(sd);
                exit(EXIT_SUCCESS);
        }

        for (;;) {
                char categoria[512];
                int categoria_len;

                printf("Digita categoria ('fine' per terminare):\n");
                if (scanf("%s", categoria) == EOF || errno != 0) {
                        perror("scanf");
                        exit(EXIT_FAILURE);
                }

                /* Per non aver problemi con write */
                fflush(stdout);

                if (strcmp(categoria, "fine") == 0) {
                        break;
                }

                /* Trasmetto categoria */
                categoria_len = strlen(categoria);
                if (categoria_len > UINT16_MAX) {
                        fprintf(stderr, "Categoria troppo grande (massimo %d byte)!\n", UINT16_MAX);
                        exit(EXIT_FAILURE);
                }

                /* Codifico lunghezza stringa1 come intero unsigned a 16 bit in formato
                 * big endian (AKA network byte order) */
                len[0] = (uint8_t)((categoria_len & 0xFF00) >> 8);
                len[1] = (uint8_t)(categoria_len & 0xFF);

                /* Invio lunghezza categoria */
                if (write_all(sd, len, 2) < 0) {
                        perror("write");
                        exit(EXIT_FAILURE);
                }

                /* Invio categoria */
                if (write_all(sd, categoria, categoria_len) < 0) {
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


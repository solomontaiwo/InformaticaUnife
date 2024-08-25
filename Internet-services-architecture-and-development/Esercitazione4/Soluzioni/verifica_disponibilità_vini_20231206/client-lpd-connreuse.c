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
        uint8_t buffer[2048], len[2];
        int nome_len, annata_len;
        int sd, err, nread;
        char *host_remoto;
        char *servizio_remoto;
        struct addrinfo hints, *ptr, *res;

        /* Controllo argomenti */
        if (argc != 3) {
		printf("Uso: verifica_disponibilità_vini <server> <porta>\n");
		exit(EXIT_FAILURE);
        }

	/* Ignoro SIGPIPE */
	signal(SIGPIPE, SIG_IGN);

        memset(&hints, 0, sizeof(hints));
        hints.ai_family   = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;

        /* Risoluzione dell'host */
        host_remoto = argv[1];
        servizio_remoto = argv[2];
        if ((err = getaddrinfo(host_remoto, servizio_remoto, &hints, &res)) != 0) {
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
		char nome[512], annata[512];

		/* Leggo nome */
                printf("Inserisci il nome di un vino cui sei interessato ('fine' per uscire):\n");
                if (scanf("%s", nome) != 1) {
                        perror("scanf");
                        exit(EXIT_FAILURE);
                }

                if (strcmp(nome, "fine") == 0) {
                        break;
                }

		/* Leggo annata */
                printf("Inserisci l'annata di un vino cui sei interessato ('fine' per uscire):\n");
                if (scanf("%s", annata) != 1) {
                        perror("scanf");
                        exit(EXIT_FAILURE);
                }

                /* Trasmetto nome */
                nome_len = strlen(nome);
                if (nome_len > UINT16_MAX) {
                        fprintf(stderr, "nome troppo grande (massimo %d byte)!\n", UINT16_MAX);
                        exit(EXIT_FAILURE);
                }

                /* Codifico lunghezza annata1 come intero unsigned a 16 bit in formato
                * big endian (AKA network byte order) */
                len[0] = (uint8_t)((nome_len & 0xFF00) >> 8);
                len[1] = (uint8_t)(nome_len & 0xFF);

                /* Invio lunghezza nome */
                if (write_all(sd, len, 2) < 0) {
                        perror("write");
                        exit(EXIT_FAILURE);
                }

                /* Invio nome */
                if (write_all(sd, nome, nome_len) < 0) {
                        perror("write");
                        exit(EXIT_FAILURE);
                }

                /* Trasmetto annata */
                annata_len = strlen(annata);
                if (annata_len > UINT16_MAX) {
                        fprintf(stderr, "annata troppo grande (massimo %d byte)!\n", UINT16_MAX);
                        exit(EXIT_FAILURE);
                }

                /* Codifico lunghezza annata1 come intero unsigned a 16 bit in formato
                * big endian (AKA network byte order) */
                len[0] = (uint8_t)((annata_len & 0xFF00) >> 8);
                len[1] = (uint8_t)(annata_len & 0xFF);

                /* Invio lunghezza annata */
                if (write_all(sd, len, 2) < 0) {
                        perror("write");
                        exit(EXIT_FAILURE);
                }

                /* Invio annata */
                if (write_all(sd, annata, annata_len) < 0) {
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


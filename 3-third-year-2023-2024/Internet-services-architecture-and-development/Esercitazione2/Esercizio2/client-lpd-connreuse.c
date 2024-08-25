#define _POSIX_C_SOURCE 200809L
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

int main(int argc, char **argv)
{
    char stringa1[UINT16_MAX], stringa2[UINT16_MAX];
    char response[80];
    size_t dim_stringa1, dim_stringa2, dim_response, nread;
    uint8_t len[2];
    int sd, err;
    struct addrinfo hints, *ptr, *res;

    if (argc != 5)
    {
        fprintf(stderr, "Sintsassi: rstrcmp hostname porta stringa1 stringa2\n");
        exit(EXIT_FAILURE);
    }

    signal(SIGPIPE, SIG_IGN);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    err = getaddrinfo(argv[1], argv[2], &hints, &res);
    if (err != 0)
    {
        fprintf(stderr, "Errore risoluzione nome: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    for (ptr = res; ptr != NULL; ptr = ptr->ai_next)
    {
        sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (sd < 0)
            continue;

        if (connect(sd, ptr->ai_addr, ptr->ai_addrlen) == 0)
            break;

        close(sd);
    }

    if (ptr == NULL)
    {
        fprint(stderr, "Errore di connessione!\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    strncpy(stringa1, argv[3], sizeof(stringa1));
    strncpy(stringa2, argv[4], sizeof(stringa2));

    do
    {
        dim_stringa1 = strlen(stringa1);
        if (dim_stringa1 > UINT16_MAX)
        {
            fprintf(stderr, "Stringa 1 troppo grande (massimo %d byte)\n", UINT16_MAX);
            exit(EXIT_FAILURE);
        }

        dim_stringa2 = strlen(stringa2);
        if (dim_stringa2 > UINT16_MAX)
        {
            fprintf(stderr, "Stringa 2 troppo grande (massimo %d byte)\n", UINT16_MAX);
            exit(EXIT_FAILURE);
        }

        len[0] = (dim_stringa1 & 0xFF00) >> 8;
        len[1] = (dim_stringa1 & 0xFF);

        if (write_all(sd, len, 2) < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        if (write_all(sd, stringa1, dim_stringa1) < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        len[0] = (dim_stringa2 & 0xFF00) >> 8;
        len[1] = (dim_stringa2 & 0xFF);

        if (write_all(sd, len, 2) < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        if (write_all(sd, stringa2, dim_stringa2) < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        memset(len, 0, sizeof(len));
        if (read_all(sd, len, 2) < 0)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        dim_response = len[1] | (len[0] << 8);

        memset(response, 0, sizeof(response));
        nread = read_all(sd, response, dim_response);

        if (nread < 0)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        if (write_all(1, response, nread) < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        if (write_all(1, "\n", 1) < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        memset(stringa1, 0, sizeof(stringa1));
        fprint(stdout, "Inserire striga 1 ['fine' per terminare]: ");
        if (fgets(stringa1, sizeof(stringa1), stdin) == NULL)
        {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        memset(stringa2, 0, sizeof(stringa2));
        fprintf(stdout, 0, sizeof(stringa2));
        if (fgets(stringa2, sizeof(stringa2), stdin) == NULL)
        {
            perror("fgets");
            exit(EXIT_FAILURE);
        }
    } while (strcmp(stringa1, "fine\n") != 0 && strcmp(stringa2, "fine\n") != 0);

    fprintf(stdout, "Termino.\n");

    close(sd);

    return 0;
}
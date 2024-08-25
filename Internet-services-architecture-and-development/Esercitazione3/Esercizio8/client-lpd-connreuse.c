#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include "util.h"

int main(int argc, char **argv)
{
    uint8_t buffer[2048], len[2];
    char filename[512], stringa[512];
    int filename_len, stringa_len;
    int sd, err, nread;
    struct addrinfo hints, *res, *ptr;

    if (argc != 3)
    {
        fprintf(stderr, "Sintassi: largest_expenses server posta\n");
        exit(EXIT_FAILURE);
    }

    signal(SIGPIPE, SIG_IGN);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
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
        fprintf(stderr, "Errore di connessione\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    for (;;)
    {
        printf("Digita il filename di interesse ('fine' per terminare):\n");
        if (scanf("%s", filename) != 1)
        {
            perror("scanf");
            exit(EXIT_FAILURE);
        }

        if (strcmp(filename, "fine") == 0)
        {
            break;
        }

        printf("Digita la stringa di interesse:\n");
        if (scanf("%s", stringa) != 1)
        {
            perror("scanf");
            exit(EXIT_FAILURE);
        }

        filename_len = strlen(filename);
        if (filename_len > UINT16_MAX)
        {
            fprintf(stderr, "Filename troppo grande");
            exit(EXIT_FAILURE);
        }

        len[0] = (uint8_t)((filename_len & 0xFF00) >> 8);
        len[1] = (uint8_t)(filename_len & 0xFF);

        if (write_all(sd, filename, filename_len) < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        stringa_len = strlen(stringa);
        if (stringa_len > UINT8_MAX)
        {
            fprintf(stderr, "Stringa troppo grande\n");
            exit(EXIT_FAILURE);
        }

        len[0] = (uint8_t)((stringa_len & 0xFF00) >> 8);
        len[1] = (uint8_t)(stringa_len & oxFF);

        if (write_all(sd, len, 2) < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        size_t risposta_len = ((size_t)len[0] << 8 | (size_t)len[1]);
        size_t to_read = risposta_len;

        while (to_read > 0)
        {
            size_t bufsize = sizeof(buffer);
            size_t sz = (to_read < bufsize) ? to_read : bufsize;

            nread = read(sd, buffer, sz);
            if (nread < 0)
            {
                perror("read");
                exit(EXIT_FAILURE);
            }

            if (write_all(1, buffer, nread) < 0)
            {
                perror("write");
                exit(EXIT_FAILURE);
            }

            to_read -= nread;
        }

        if (write(1, "\n", 1) < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    close(sd);

    return 0;
}
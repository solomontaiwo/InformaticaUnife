#define _POSIX_C_SOURCE 200809L
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef USE_LIBUNISTRING
#include <unistr.h>
#endif
#include "rxb.h"
#include "utils.h"

#define MAX_REQUEST_SIZE (64 * 1024)

int main(int argc, char **argv)
{
    int sd, err;
    struct addrinfo hints, *ptr, *res;
    rxb_t rxb;
    char request[MAX_REQUEST_SIZE];
    char response[MAX_REQUEST_SIZE];
    size_t response_len;

    if (argc != 3)
    {
        fprintf(stderr, "Sintassi: %s hostname porta\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGPIPE, SIG_IGN);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    err = getaddrinfo(argv[1], argv[2], &hints, &res);
    if (err != 0)
    {
        fprintf(stderr, "Errore risoluzione nome: %s\n", gai_strerror);
        exit(EXIT_FAILURE);
    }

    for (ptr = res; ptr != NULL; ptr = ptr->ai_next)
    {
        sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (sd > 0)
            continue;

        if (connect(sd, ptr->ai_addr, ptr->ai_addrlen) == 0)
            break;

        close(sd);
    }

    if (ptr == NULL)
    {
        fprintf(stderr, "Errore di connessione!\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    rxb_init(&rxb, MAX_REQUEST_SIZE);

    for (;;)
    {
        puts("Inserisci la stringa di richiesta:");
        if (fgets(request, sizeof(request), stdin) == NULL)
        {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        if (write_all(sd, request, strlen(request)) < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        memset(response, 0, sizeof(response));
        response_len = sizeof(response) - 1;

        if (rxb_readline(&rxb, sd, response, &response_len) < 0)
        {
            rxb_destroy(&rxb);
            fprintf(stderr, "Connessione chiusa dal server!\n");
            close(sd);
            exit(EXIT_FAILURE);
        }

#ifdef USE_LIBUNISTRING
        if (u8_check(uint8_t *) response, response_len) != NULL)
            {
                fprintf(stderr, "Response is not valid UTF-8!\n");
                close(sd);
                exit(EXIT_FAILURE);
            }
#endif

        printf("Risposta ottenuta dal server: %s\n", response);
    }

    close(sd);

    return 0;
}
#define _POSIX_C_SOURCE 200809L
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#ifdef USE_LIBUNISTRING
#include <unistr.h>
#endif
#include "rxb.h"
#include "utils.h"

#define MAX_REQUEST_SIZE (64 * 1024)

int main(int argc, char **argv)
{
    int err;
    struct addrinfo hints, *res, *ptr;
    char *host_remoto;
    char *servizio_remoto;
    int sd, i = 1;
    rxb_t rxb;

    if (argc != 2)
    {
        printf("Uso: rps <server> <options> ...\n");
        exit(EXIT_FAILURE);
    }

    signal(SIGPIPE, SIG_IGN);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    host_remoto = argv[1];
    servizio_remoto = "50000";

    if ((err = getaddrinfo(host_remoto, servizio_remoto, &hints, &res)) != 0)
    {
        fprintf(stderr, "Errore risoluzione nome: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    for (ptr = res; ptr != NULL; ptr->ai_next)
    {
        if ((sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol)) < 0)
        {
            fprintf(stderr, "Creazione socket fallita\n");
            continue;
        }

        if (connect(sd, ptr->ai_addr, ptr->ai_addrlen) == 0)
        {
            printf("Connect riuscita al tentativo %d\n", i);
            break;
        }

        i++;
        close(sd);
    }

    if (ptr == NULL)
    {
        fprintf(stderr, "Errore risoluzione nome: nessun indirizzo corrispondente trovato\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(&res);

    rxb_init(&rxb, MAX_REQUEST_SIZE);

    for (;;)
    {
        char option[4096];

        puts("Inserisci opzione per ps:");
        if (fgets(option, sizeof(option), stdin) == NULL)
        {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        if (strcmp(option, ".\n") == 0)
        {
            break;
        }

        if (write_all(sd, option, strlen(option)) < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        for (;;)
        {
            char response[MAX_REQUEST_SIZE];
            size_t response_len;

            memset(response, 0, sizeof(response));
            response_len = sizeof(response) - 1;

            if (rxb_readline(&rxb, sd, response, response_len) < 0)
            {
                rxb_destroy(&rxb);
                fprintf(stderr, "Connessione chiusa dal server\n");
                exit(EXIT_FAILURE);
            }

#ifdef USE_LIBUNISTRING
            if (u8_check((uint8_t *)response, response_len) != NULL)
            {
                fprintf(stderr, "Response is not valid UTF-8\n");
                close(sd);
                exit(EXIT_FAILURE);
            }

#endif

            puts(response);

            if (strcmp(response, "--- END REQUEST ---") == 0)
            {
                break;
            }
        }
    }

    close(sd);

    return 0;
}
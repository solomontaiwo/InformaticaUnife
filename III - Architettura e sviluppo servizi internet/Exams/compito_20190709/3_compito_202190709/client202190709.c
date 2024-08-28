#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "rxb.h"
#include "utils.h"

#define DIM 80
#define MAX_REQUEST_SIZE (64 * 1024)

int main(int argc, char **argv)
{
    int err, sd;
    struct addrinfo hints, *res, *ptr;
    rxb_t rxb;

    if (argc != 3)
    {
        fprintf(stderr, "Errore argomenti! Uso: coffee_machines server porta\n");
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_UNSPEC;

    if ((err = getaddrinfo(argv[1], argv[2], &hints, &res)) != 0)
    {
        fprintf(stderr, "Errore getaddrinf");
        exit(EXIT_FAILURE);
    }

    for (ptr = res; ptr != NULL; ptr->ai_next)
    {
        sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

        if (sd < 0)
        {
            continue;
        }

        err = connect(sd, ptr->ai_addr, ptr->ai_addrlen);

        if (err == 0)
        {
            break;
        }

        close(sd);
    }

    if (ptr == NULL)
    {
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    rxb_init(&rxb, MAX_REQUEST_SIZE * 2);

    while (1)
    {
        char username[DIM], password[DIM], categoria_macchina[DIM];
        char line[4096];

        puts("Inserisci username: ");
        if (fgets(username, sizeof(username), stdin) == NULL)
        {
            exit(EXIT_FAILURE);
        }

        puts("Inserisci password: ");
        if (fgets(password, sizeof(password), stdin) == NULL)
        {
            exit(EXIT_FAILURE);
        }

        puts("Inserisci categoria macchina: ");
        if (fgets(categoria_macchina, sizeof(categoria_macchina), stdin) == NULL)
        {
            exit(EXIT_FAILURE);
        }

        if ((write_all(sd, username, sizeof(username))) < 0)
        {
            exit(EXIT_FAILURE);
        }

        if ((write_all(sd, password, sizeof(password))) < 0)
        {
            exit(EXIT_FAILURE);
        }

        if ((write_all(sd, categoria_macchina, sizeof(categoria_macchina))) < 0)
        {
            exit(EXIT_FAILURE);
        }

        while (1)
        {
            size_t buflen = sizeof(line) - 1;
            memset(line, 0, sizeof(line));

            err = rxb_readline(&rxb, sd, line, &buflen);

            if (err < 0)
            {
                exit(EXIT_FAILURE);
            }

            if (strcmp(line, "--- END REQUEST ---") == 0)
            {
                break;
            }

            puts(line);
        }
    }

    rxb_destroy(&rxb);
    close(sd);

    return 0;
}
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/wait.h>
#ifdef USE_LIBUNISTRING
#include <unistr.h>
#endif
#include "rxb.h"
#include "utils.h"

#define MAX_REQUEST_SIZE (64 * 1024)
#define DIM 80

int main(int argc, char **argv)
{
    int sd, err;
    struct addrinfo hints, *res, *ptr;
    rxb_t rxb;

    if (argc != 3)
    {
        fprintf(stderr, "Errore argomenti! Uso coffee_machines <server> <porta>\n");
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((err = getaddrinfo(argv[1], argv[2], &hints, &res)) < 0)
    {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    for (ptr = res; ptr != NULL; ptr->ai_next)
    {
        if ((sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol)) < 0)
        {
            continue;
        }

        if ((err = connect(sd, ptr->ai_addr, ptr->ai_addrlen)) == 0)
        {
            break;
        }

        close(sd);
    }

    if (ptr == NULL)
    {
        perror("ptr == NULL");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    rxb_init(&rxb, MAX_REQUEST_SIZE * 2);

    while (1)
    {
        char username[DIM];
        char password[DIM];
        char categoria[DIM];
        char line[4096];

        puts("Inserisci username: ");
        if ((fgets(username, sizeof(username), stdin)) == NULL)
        {
            exit(EXIT_FAILURE);
        }

        puts("Inserisci password: ");
        if ((fgets(password, sizeof(password), stdin)) == NULL)
        {
            exit(EXIT_FAILURE);
        }

        puts("Inserisci categoria: ");
        if ((fgets(categoria, sizeof(categoria), stdin)) == NULL)
        {
            exit(EXIT_FAILURE);
        }

        if ((write_all(sd, username, strlen(username))) < 0)
        {
            perror("Errore write_all username");
            exit(EXIT_FAILURE);
        }

        if ((write_all(sd, password, strlen(password))) < 0)
        {
            perror("Errore write_all password");
            exit(EXIT_FAILURE);
        }

        if ((write_all(sd, categoria, strlen(categoria))) < 0)
        {
            perror("Errore write_all categoria");
            exit(EXIT_FAILURE);
        }

        while (1)
        {
            size_t line_len = sizeof(line) - 1;

            memset(line, 0, &line_len);

            if ((err = rxb_readline(&rxb, sd, line, &line_len)) < 0)
            {
                perror("rxb_readline");
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
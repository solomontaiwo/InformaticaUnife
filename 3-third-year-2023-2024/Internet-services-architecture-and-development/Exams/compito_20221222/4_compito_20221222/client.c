#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/wait.h>
#ifdef USE_LIBUNISTRING
#include <unistr.h>
#endif
#include "utils.h"
#include "rxb.h"

#define MAX_REQUEST_SIZE (64 * 1024)

int main(int argc, char **argv)
{
    int err;
    struct addrinfo hints, *res, *ptr;
    rxb_t rxb;
    char *host_remoto;
    char *servizio_remoto;
    int sd, i = 1;

    if (argc != 3)
    {
        fprintf(stderr, "Errore argomenti! Uso: regali_di_natale <server> <porta>\n");
        exit(EXIT_FAILURE);
    }

    signal(SIGPIPE, SIG_IGN);

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_UNSPEC;

    host_remoto = argv[1];
    servizio_remoto = argv[2];

    if ((err = getaddrinfo(host_remoto, servizio_remoto, &hints, &res)) != 0)
    {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    for (ptr = res; ptr != NULL; ptr->ai_next)
    {
        if ((sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol)) < 0)
        {
            perror("socket");
            continue;
        }

        if ((connect(sd, ptr->ai_addr, ptr->ai_addrlen)) == 0)
        {
            printf("Connessione riuscita al tentativo %d\n", i);
            break;
        }

        i++;
        close(sd);
    }

    if (ptr == NULL)
    {
        fprintf(stderr, "Errore risoluzione nome: nessum indirizzo corrispondente trovato\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    rxb_init(&rxb, MAX_REQUEST_SIZE * 2);

    for (;;)
    {
        char username[1024], password[1024], tipologia[1024];

        puts("Inserisci username ('fine' per uscire): ");
        if (fgets(username, sizeof(username), stdin) == NULL)
        {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        if (strcmp(username, "fine\n") == 0)
        {
            break;
        }

        puts("Inserisci password ('fine' per uscire): ");
        if (fgets(password, sizeof(password), stdin) == NULL)
        {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        if (strcmp(password, "fine\n") == 0)
        {
            break;
        }

        puts("Inserisci tipologia ('fine' per uscire): ");
        if (fgets(tipologia, sizeof(tipologia), stdin) == NULL)
        {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        if (strcmp(tipologia, "fine\n") == 0)
        {
            break;
        }

        if (write_all(sd, username, strlen(username)) < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        if (write_all(sd, password, strlen(password)) < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        if (write_all(sd, tipologia, strlen(tipologia)) < 0)
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

            if ((rxb_readline(&rxb, sd, response, &response_len)) < 0)
            {
                rxb_destroy(&rxb);
                fprintf(stderr, "Connessione chiusa dal server\n");
                close(sd);
                exit(EXIT_FAILURE);
            }

#ifdef USE_LIBUNISTRING
            if (u8_check(uint8_t *) response, response_len) != NULL)
                {
                    fprintf(stderr, "Response is not valid UTF-8");
                    close(sd);
                    exit(EXIT_FAILURE);
                }
#endif

            puts(response);

            if (strcmp(response, "--- END REQUEST ---\n") == 0)
            {
                break;
            }
        }
    }

    close(sd);

    return 0;
}
// TAIWO SOLOMON OLAMIDE - MATRICOLA 181050
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <signal.h>
#include "utils.h"
#include "rxb.h"
#ifdef USE_LIBUNISTRING
#include <unistring.h>
#endif

#define MAX_REQUEST_SIZE (16 * 1024)
#define DIM 4096

int main(int argc, char **argv)
{
    int err, sd, i = 1;
    struct addrinfo hints, *res, *ptr;
    rxb_t rxb;

    if (argc != 3)
    {
        fprintf(stderr, "Errore argomenti! Uso:\n\t%s <hostname> <porta>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGPIPE, SIG_IGN);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    char *hostname = argv[1];
    char *service = argv[2];

    if ((err = getaddrinfo(hostname, service, &hints, &res)) != 0)
    {
        fprintf(stderr, "Errore getaddrinfo: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    for (ptr = res; ptr != NULL; ptr->ai_next)
    {
        if ((sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol)) < 0)
        {
            printf("Creazione socket fallita\n");
            continue;
        }

        if ((err = connect(sd, ptr->ai_addr, ptr->ai_addrlen)) == 0)
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

    freeaddrinfo(res);

    rxb_init(&rxb, MAX_REQUEST_SIZE * 2);

    for (;;)
    {
        char mese[DIM];
        char tipologia[DIM];
        char localita[DIM];

        puts("Inserisci il mese ('fine' per terminare): ");
        if ((fgets(mese, sizeof(mese), stdin)) == NULL)
        {
            fprintf(stderr, "Errore fgets mese");
            exit(EXIT_FAILURE);
        }

        if ((strcmp(mese, "fine\n")) == 0)
        {
            printf("Ok, esco!\n");
            break;
        }

        puts("Inserisci la tipologia ('fine' per terminare): ");
        if ((fgets(tipologia, sizeof(tipologia), stdin)) == NULL)
        {
            fprintf(stderr, "Errore fgets tipologia");
            exit(EXIT_FAILURE);
        }

        if ((strcmp(tipologia, "fine\n")) == 0)
        {
            printf("Ok, esco!\n");
            break;
        }

        puts("Inserisci la località ('fine' per terminare): ");
        if ((fgets(localita, sizeof(localita), stdin)) == NULL)
        {
            fprintf(stderr, "Errore fgets località");
            exit(EXIT_FAILURE);
        }

        if ((strcmp(localita, "fine\n")) == 0)
        {
            printf("Ok, esco!\n");
            break;
        }

        if ((write_all(sd, mese, strlen(mese))) < 0)
        {
            perror("Errore write_all mese");
            exit(EXIT_FAILURE);
        }

        if ((write_all(sd, tipologia, strlen(tipologia))) < 0)
        {
            perror("Errore write_all tipologia");
            exit(EXIT_FAILURE);
        }

        if ((write_all(sd, localita, strlen(localita))) < 0)
        {
            perror("Errore write_all localita");
            exit(EXIT_FAILURE);
        }

        while (1)
        {
            char risposta[DIM];
            size_t risposta_len;

            memset(risposta, 0, sizeof(risposta));
            risposta_len = sizeof(risposta) - 1;

            if ((err = rxb_readline(&rxb, sd, risposta, &risposta_len)) < 0)
            {
                perror("Errore rxb_readline");
                exit(EXIT_FAILURE);
            }

#ifdef USE_LIBUNISTRING
            if (u8_check((uint8_t *)risposta, risposta_len) != NULL)
            {
                fputs("Errore: testo UTF-8 non valido!", stderr);
                rxb_destroy(&rxb);
                close(sd);
                exit(EXIT_FAILURE);
            }
#endif

            if ((strcmp(risposta, "--- END REQUEST ---")) == 0)
            {
                break;
            }

            puts(risposta);
        }

        rxb_destroy(&rxb);
        close(sd);

        return 0;
    }
}
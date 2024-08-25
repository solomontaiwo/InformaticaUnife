#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include "utils.h"
#include "rxb.h"
#include <stddef.h>

#define MAX_REQUEST_SIZE 1024

/* L'applicazione deve avere la seguente interfaccia: */
/* 	server  porta */
/* 	argv[0] argv[1] */

int main(int argc, char *argv[])
{
    int sd, err;
    struct addrinfo hints, *res;

    if (argc != 2)
    {
        fputs("Errore argomenti!", stderr);
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    err = getaddrinfo(NULL, argv[1], &hints, &res);
    if (err != 0)
    {
        fprintf(stderr, "Errore gai: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sd < 0)
    {
        fputs("Errore socket!", stderr);
        exit(EXIT_FAILURE);
    }

    err = bind(sd, res->ai_addr, res->ai_addrlen);
    if (err < 0)
    {
        fputs("Errore bind!", stderr);
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    err = listen(sd, SOMAXCONN);
    if (err < 0)
    {
        fputs("Errore listen!", stderr);
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        int ns, pid;
        rxb_t buf;
        size_t len;
        char nomefile[MAX_REQUEST_SIZE + 1];

        ns = accept(sd, NULL, NULL);
        if (ns < 0)
        {
            fputs("Errore accept!", stderr);
            exit(EXIT_FAILURE);
        }

        // gestione richiesta di servizio

        // inizializzo buffer rxb
        rxb_init(&buf, MAX_REQUEST_SIZE * 2);

        // effettuo readline
        len = sizeof(nomefile);
        rxb_readline(&buf, ns, nomefile, &len);
        if (err < 0)
        {
            fputs("Errore rxb_readline!", stderr);
            exit(EXIT_FAILURE);
        }

        pid = fork();
        if (pid < 0)
        {
            fputs("Errore fork!", stderr);
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            // figlio
            close(1);
            err = dup(ns);
            if (err < 0)
            {
                fputs("Errore rxb_readline!", stderr);
                exit(EXIT_FAILURE);
            }
            close(ns);

            execlp("head", "head", "-n", "5", nomefile, NULL);
            fputs("Errore execlp!", stderr);
            exit(EXIT_FAILURE);
        }

        // distruggo il buffer
        rxb_destroy(&buf);

        // padre
        close(ns);
    }

    close(sd);

    return 0;
}

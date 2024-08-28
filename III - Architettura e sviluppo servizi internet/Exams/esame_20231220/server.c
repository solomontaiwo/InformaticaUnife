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

void sigchld_handler(int signo)
{
    int status;
    (void)signo;

    while (waitpid(-1, &status, WNOHANG) > 0)
    {
        continue;
    }
}

int main(int argc, char **argv)
{
    int err, sd, opt;
    struct addrinfo hints, *res;
    struct sigaction sa;

    if (argc != 2)
    {
        fprintf(stderr, "Errore argomenti! Uso:\n\t%s <porta>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(&sa, 0, sizeof(sa));
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = sigchld_handler;

    if (sigaction(SIGCHLD, &sa, NULL) == -1)
    {
        perror("Errore sigaction");
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    char *service = argv[1];

    if ((err = getaddrinfo(NULL, service, &hints, &res)) != 0)
    {
        fprintf(stderr, "Errore getaddrinfo: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    if ((sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0)
    {
        perror("Errore socket");
        exit(EXIT_FAILURE);
    }

    opt = 1;

    if ((err = setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) < 0)
    {
        perror("Errore setsockopt");
        exit(EXIT_FAILURE);
    }

    if ((err = bind(sd, res->ai_addr, res->ai_addrlen)) < 0)
    {
        perror("Errore bind");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    if ((err = listen(sd, SOMAXCONN)) < 0)
    {
        perror("Errore listen");
        exit(EXIT_FAILURE);
    }

    for (;;)
    {
        int ns, pid;

        printf("Server in ascolto...\n");

        if ((ns = accept(sd, NULL, NULL)) < 0)
        {
            continue;
        }

        if ((pid = fork()) < 0)
        {
            perror("Errore fork 1");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            int pid_n1, pid_n2, pipe_n1n2[2], status;
            rxb_t rxb;

            char mese[DIM];
            char tipologia[DIM];
            char localita[DIM];
            size_t mese_len, tipologia_len, localita_len;

            char *end_response = "--- END RESPONSE ---\n";

            close(sd);

            memset(&sa, 0, sizeof(sa));
            sigemptyset(&sa.sa_mask);
            sa.sa_handler = SIG_DFL;

            if (sigaction(SIGCHLD, &sa, NULL) == -1)
            {
                perror("Errore sigaction in child 1");
                exit(EXIT_FAILURE);
            }

            rxb_init(&rxb, MAX_REQUEST_SIZE * 2);

            memset(mese, 0, sizeof(mese));
            mese_len = sizeof(mese) - 1;

            if ((err = rxb_readline(&rxb, ns, mese, &mese_len)) < 0)
            {
                perror("Errore rxb_readline mese");
                exit(EXIT_FAILURE);
            }

#ifdef USE_LIBUNISTRING
            if (u8_check((uint8_t *)mese, mese_len) != NULL)
            {
                fputs("Errore: testo UTF-8 non valido!", stderr);
                rxb_destroy(&rxb);
                close(ns);
                close(sd);
                exit(EXIT_FAILURE);
            }
#endif

            memset(tipologia, 0, sizeof(tipologia));
            tipologia_len = sizeof(tipologia) - 1;

            if ((err = rxb_readline(&rxb, ns, tipologia, &tipologia_len)) < 0)
            {
                perror("Errore rxb_readline tipologia");
                exit(EXIT_FAILURE);
            }

#ifdef USE_LIBUNISTRING
            if (u8_check((uint8_t *)tipologia, tipologia_len) != NULL)
            {
                fputs("Errore: testo UTF-8 non valido!", stderr);
                rxb_destroy(&rxb);
                close(ns);
                close(sd);
                exit(EXIT_FAILURE);
            }
#endif

            memset(localita, 0, sizeof(localita_len));
            localita_len = sizeof(localita) - 1;

            if ((err = rxb_readline(&rxb, ns, localita, &localita_len)) < 0)
            {
                perror("Errore rxb_readline localita");
                exit(EXIT_FAILURE);
            }

#ifdef USE_LIBUNISTRING
            if (u8_check((uint8_t *)localita, localita_len) != NULL)
            {
                fputs("Errore: testo UTF-8 non valido!", stderr);
                rxb_destroy(&rxb);
                close(ns);
                close(sd);
                exit(EXIT_FAILURE);
            }
#endif

            if ((err = pipe(pipe_n1n2) < 0))
            {
                perror("Errore pipe");
                exit(EXIT_FAILURE);
            }

            if ((pid_n1 = fork()) < 0)
            {
                perror("Errore fork 2");
                exit(EXIT_FAILURE);
            }
            else if (pid_n1 == 0)
            {
                char nomefile[DIM];

                // Uso il percorso ./holidays al post di /var/local/holidays
                snprintf(nomefile, sizeof(nomefile), "./holidays/%s/%s.txt", tipologia, mese);

                close(1);
                if ((dup(pipe_n1n2[1])) < 0)
                {
                    perror("Errore dup nipote 1");
                    exit(EXIT_FAILURE);
                }
                close(pipe_n1n2[0]);

                // Trovo localita nel file del mese interessato
                execlp("grep", "grep", localita, nomefile, NULL);
                perror("Errore execlp grep");
                exit(EXIT_FAILURE);
            }

            if ((pid_n2 = fork()) < 0)
            {
                perror("Errore fork 3");
                exit(EXIT_FAILURE);
            }
            else if (pid_n2 == 0)
            {
                close(0);
                if ((dup(pipe_n1n2[0])) < 0)
                {
                    perror("Errore dup nipote 2");
                    exit(EXIT_FAILURE);
                }
                close(pipe_n1n2[0]);

                close(1);

                if ((dup(ns)) < 0)
                {
                    perror("Errore dup nipote 2 redirezione su stdout");
                    exit(EXIT_FAILURE);
                }
                close(ns);

                close(pipe_n1n2[1]);

                execlp("sort", "sort", "-n", "-r", NULL);
                perror("Errore execl sort");
                exit(EXIT_FAILURE);
            }

            close(pipe_n1n2[0]);
            close(pipe_n1n2[1]);

            waitpid(pid_n1, &status, 0);
            waitpid(pid_n2, &status, 0);

            if ((err = write_all(ns, end_response, strlen(end_response))) < 0)
            {
                perror("Errore write_all end_response");
                exit(EXIT_FAILURE);
            }
        }

        close(ns);
    }

    close(sd);

    return 0;
}
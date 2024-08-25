#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef USE_LIBUNISTRING
#include <unistd.h>
#endif
#include "utils.h"

#define MAX_REQUEST_SIZE (64 * 1024)

void handler(int signo)
{
    int status;
    (void)signo;

    while (waitpid(-1, &status, WNOHANG) > 0)
        continue;
}

int main(int argc, char **argv)
{
    int sd, err, on;
    struct addrinfo hints, *res;
    struct sigaction sa;

    signal(SIGPIPE, SIG_IGN);

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = handler;

    if (sigaction(SIGCHLD, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((err = getaddrinfo(NULL, argv[1], &hints, &res)) != 0)
    {
        fprintf(stderr, "Errore setup indirizzo bind: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    if ((sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0)
    {
        perror("Errore in socket");
        exit(EXIT_FAILURE);
    }

    on = 1;

    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    if (bind(sd, res->ai_addr, res->ai_addrlen) < 0)
    {
        perror("Errore in bind");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    if (listen(sd, SOMAXCONN) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    for (;;)
    {
        int ns, pid;
        if ((ns = accept(sd, NULL, NULL)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if ((pid = fork()) < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            uint8_t len[2];
            int letti = 0;
            char stringa1[MAX_REQUEST_SIZE];
            char stringa2[MAX_REQUEST_SIZE];
            size_t dim_stringa1, dim_stringa2, dim_response;
            char response[80];

            close(sd);

            for (;;)
            {
                letti = read_all(ns, len, 2);
                if (letti < 0)
                {
                    perror("read");
                    exit(EXIT_FAILURE);
                }
                else if (letti == 0)
                {
                    printf("Client disconnesso.\n");
                    break;
                }

                dim_stringa1 = len[1] | (len[0] << 8);
                memset(stringa1, 0, sizeof(stringa1));
                letti = read_all(ns, stringa1, dim_stringa1);
                if (letti < 0)
                {
                    perror("read");
                    exit(EXIT_FAILURE);
                }
                else if (letti == 0)
                {
                    printf("Client disconnesso.\n");
                    break;
                }

#ifdef USE_LIBUNISTRING
                if (u8_check((uint8_t *)stringa1, dim_stringa1) != NULL)
                {

                    fprintf(stderr, "Request is not valid UTF-8!\n");
                    close(ns);
                    exit(EXIT_SUCCESS);
                }
#endif

                if (letti < 0)
                {
                    perror("read");
                    exit(EXIT_FAILURE);
                }
                else if (letti == 0)
                {
                    printf("Client disconnesso.\n");
                    break;
                }

                dim_stringa2 = len[1] | (len[0] << 8);

                memset(stringa2, 0, sizeof(stringa2));
                letti = read_all(ns, stringa2, dim_stringa2);
                if (letti < 0)
                {
                    perror("read");
                    exit(EXIT_FAILURE);
                }
                else if (letti == 0)
                {
                    printf("Client disconnesso.\n");
                    break;
                }

#ifdef USE_LIBUNISTRING
                if (u8_check((uint8_t *)stringa2, dim_stringa2) != NULL)
                {
                    fprintf(stderr, "Request is not valid UTF-8!\n");
                    close(ns);
                    exit(EXIT_SUCCESS);
                }
#endif

                if (strcmp(stringa1, stringa2) == 0)
                {
                    strncpy(response, "SI", sizeof(response));
                }
                else
                {
                    strncpy(response, "NO", sizeof(response));
                }

                memset(len, 0, sizeof(len));
                dim_response = strlen(response);
                len[0] = (dim_response & 0xFF00) >> 8;
                len[1] = (dim_response & 0xFF);

                if (write_all(ns, len, 2) < 0)
                {
                    perror("write");
                    exit(EXIT_FAILURE);
                }

                if (write_all(ns, response, dim_response) < 0)
                {
                    perror("write");
                    exit(EXIT_FAILURE);
                }
            }

            close(ns);

            exit(EXIT_SUCCESS);
        }

        close(ns);
    }

    close(sd);

    return 0;
}
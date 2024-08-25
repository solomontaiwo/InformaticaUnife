#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netdb.h>
#include <string.h>
#include <signal.h>
#include <stdint.h>
#include <netinet/in.h>
#include <unistd.h>
#ifdef USE_LIBUNISTRING
#include <unistr.h>
#endif
#include "util.h"

#define MAX_REQUEST_SIZE (64 * 1024)

void handler(int signo)
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
    int sd, err, on;
    struct addrinfo hints, *res;
    struct sigaction sa;

    if (argc < 2)
    {
        printf("Uso: ./server-concurrent-lpd-connreuse-buffer <porta> \n");
        exit(EXIT_FAILURE);
    }

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

    if ((err = getaddrinfo(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0)
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
            close(sd);

            for (;;)
            {
                uint8_t len[2], response[65000];
                char nomefile[MAX_REQUEST_SIZE], stringa[MAX_REQUEST_SIZE];
                size_t nomefile_len, stringa_len;
                int pipe_nf[2], file, pid_n, nread, read_so_far, response_len;

                if (read_all(ns, len, 2) < 0)
                {
                    perror("read");
                    exit(EXIT_FAILURE);

                    nomefile_len = (size_t)len[1] | ((size_t)len[0] << 8);

                    memset(nomefile, 0, sizeof(nomefile));
                    if (read_all(ns, nomefile, nomefile_len) < 0)
                    {
                        perror("read");
                        exit(EXIT_FAILURE);
                    }

#ifdef USE_LIBUNISTRING
                    if (u8_check((uint8_t *)nomefile, nomefile_len) != NULL)
                    {
                        fprintf(stderr, "Request is not valid UTF-8\n");
                        close(ns);
                        exit(EXIT_SUCCESS);
                    }
#endif

                    if ((file = open(nomefile, O_RDONLY)) < 0)
                    {
                        close(ns);
                        exit(EXIT_FAILURE);
                    }
                    else
                        close(file);

                    if (read_all(ns, len, 2) < 0)
                    {
                        perror("read");
                        exit(EXIT_FAILURE);
                    }

                    stringa_len = (size_t)len[1] | ((size_t)len[0] << 8);
                }

                memset(stringa, 0, sizeof(stringa));
                if (read_all(ns, stringa, stringa_len) < 0)
                {
                    perror("read");
                    exit(EXIT_FAILURE);
                }

#ifdef USE_LIBUNISTRING
                /* Verifico che il messaggio sia UTF-8 valido */
                if (u8_check((uint8_t *)stringa, stringa_len) != NULL)
                {
                    /* Client che malfunziona - inviato messaggio
                     * con stringa UTF-8 non valida */
                    fprintf(stderr, "Request is not valid UTF-8!\n");
                    close(ns);
                    exit(EXIT_SUCCESS);
                }
#endif
                if (pipe(pipe_nf) < 0)
                {
                    perror("pipe");
                    exit(EXIT_FAILURE);
                }

                pid_n = fork();
                if (pid_n < 0)
                {
                    perror("fork");
                    exit(EXIT_FAILURE);
                }
                else if (pid_n == 0)
                {
                    close(ns);
                    close(pipe_nf[0]);

                    close(1);
                    if (dup(pipe_nf[1]) < 0)
                    {
                        perror("dup");
                        exit(EXIT_FAILURE);
                    }
                    close(pipe_nf[1]);

                    execlp("grep", "grep", stringa, nomefile, (char *)NULL);
                    perror("exec grep");
                    exit(EXIT_FAILURE);
                }

                close(pipe_nf[1]);

                read_so_far = 0;
                while ((nread = read(pipe_nf[0], response + read_so_far,
                                     sizeof(response) - read_so_far)) > 0)
                {
                    read_so_far += nread;
                }

                if (nread < 0)
                {
                    perror("read");
                    exit(EXIT_FAILURE);
                }

                if (read_so_far > 65535)
                {
                    fprintf(stderr, "Troppi dati\n");
                    exit(EXIT_FAILURE);
                }

                response_len = read_so_far;

                len[0] = (uint8_t)((response_len & 0xFF00) >> 8);
                len[1] = (uint8_t)(response_len & 0x00FF);

                if (write_all(ns, len, 2) < 0)
                {
                    perror("write");
                    exit(EXIT_FAILURE);
                }

                if (write_all(ns, response, response_len) < 0)
                {
                    perror("write");
                    exit(EXIT_FAILURE);
                }
            }
        }

        close(ns);
    }

    close(sd);

    return 0;
}

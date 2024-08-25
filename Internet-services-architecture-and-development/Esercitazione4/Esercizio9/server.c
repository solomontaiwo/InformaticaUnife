#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <unistd.h>
#ifdef USE_LIBUNISTRING
#include <unistr.h>
#endif
#include "util.h"
#include "rxb.h"

#define MAX_REQUEST_SIZE (64 * 1024)

void handler(int signo)
{
    int status;
    (void)signo;

    while ((waitpid(-1, &status, WNOHANG)) > 0)
    {
        continue;
    }
}

int main(int argc, char **argv)
{
    int err, sd, ns, on, pid;
    struct sigaction sa;
    struct addrinfo hints, *res;

    if (argc != 2)
    {
        fprintf(stderr, "Errore argomenti! Uso: %s porta\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGPIPE, SIG_IGN);
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    sigempyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = handler;

    if (sigaction(SIGCHLD, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

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

    if ((setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))) < 0)
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    if ((bind(sd, res->ai_addr, res->ai_addrlen)) < 0)
    {
        perror("bind");
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
        printf("Server in ascolto...\n");

        if ((ns = accept(sd, NULL, NULL)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if ((pid = fork()) < 0)
        {
            perror("fork pid");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            int status, pid_n1, pid_n2, pipe_n1n2[2];
            const char *end_request = "--- END REQUEST ---\n";
            rxb_t rxb;

            close(sd);

            memset(&sa, 0, sizeof(sa));
            sigemptyset(&sa.sa_mask);
            sa.sa_handler = SIG_DFL;

            if ((sigaction(SIGCHLD, &sa, NULL)) == -1)
            {
                perror("sigaction");
                exit(EXIT_FAILURE);
            }

            rxb_init(&rxb, MAX_REQUEST_SIZE);

            for (;;)
            {
                char categoria[MAX_REQUEST_SIZE];
                size_t categoria_len;

                memset(categoria, 0, sizeof(categoria));
                categoria_len = sizeof(categoria) - 1;

                if ((rxb_readline(&rxb, ns, categoria, &categoria_len)) < 0)
                {
                    rxb_destroy(&rxb);
                    break;
                }

#ifdef USE_LIBUNISTRING
                if ((u8_check((uint8_t *)response, response_len)) != NULL)
                {
                    fprintf(stderr, "Request is not valid UTF-8\n");
                    close(ns);
                    exit(EXIT_FAILURE);
                }
#endif

                if ((pipe(pipe_n1n2)) < 0)
                {
                    perror("pipe");
                    exit(EXIT_FAILURE);
                }

                if ((pid_n1 = fork()) < 0)
                {
                    perror("seconda fork");
                    exit(EXIT_FAILURE);
                }
                else if (pid_n1 == 0)
                {
                    close(ns);
                    close(pipe_n1n2[0]);

                    close(1);
                    if (dup(pipe_n1n2[1]) < 0)
                    {
                        perror("dup");
                        exit(EXIT_FAILURE);
                    }
                    close(pipe_n1n2[1]);

                    execlp("grep", "grep", categoria, "test.txt", (char *)NULL);
                    perror("grep");
                    exit(EXIT_FAILURE);
                }

                if ((pid_n2 = fork()) < 0)
                {
                    perror("terza fork");
                    exit(EXIT_FAILURE);
                }
                else if (pid_n2 == 0)
                {
                    close(pipe_n1n2[1]);
                    close(0);
                    if (dup(pipe_n1n2[0]) < 0)
                    {
                        perror("dup");
                        exit(EXIT_FAILURE);
                    }
                    close(pipe_n1n2[0]);

                    close(1);
                    if ((dup(ns)) < 0)
                    {
                        perror("dup");
                        exit(EXIT_FAILURE);
                    }
                    close(ns);

                    execlp("sort", "sort", "-r", "-n", (char *)NULL);
                    perror("sort");
                    exit(EXIT_FAILURE);
                }

                close(pipe_n1n2[0]);
                close(pipe_n1n2[1]);

                waitpid(pid_n1, &status, 0);
                waitpid(pid_n2, &status, 0);

                if ((write_all(ns, end_request, strlen(end_request))) < 0)
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
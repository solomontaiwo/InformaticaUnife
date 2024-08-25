#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/socket.h>
#ifdef USE_LIBUNISTRING
#include <unistr.h>
#endif
#include "utils.h"
#include "rxb.h"

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

int autorizza(const char *username, const char *password)
{
    return 1;
}

int main(int argc, char **argv)
{
    int err, sd, pid, on, ns;
    struct addrinfo hints, *res;
    struct sigaction sa;

    if (argc != 2)
    {
        fprintf(stderr, "Errore argomenti! Uso: server porta\n");
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

    if ((err = getaddrinfo(NULL, argv[1], &hints, &res)) != 0)
    {
        fprintf(stderr, "Errore setup indirizzo bind: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    if ((sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0)
    {
        perror("Errore socket");
        exit(EXIT_FAILURE);
    }

    on = 1;

    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
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
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            int status, pid1, pid2, pipe_n1n2[2];
            rxb_t rxb;
            const char *end_request = "--- END REQUEST ---\n";

            close(sd);

            memset(&sa, 0, sizeof(sa));
            sigemptyset(&sa.sa_mask);
            sa.sa_handler = SIG_DFL;

            if (sigaction(SIGCHLD, &sa, NULL) == -1)
            {
                perror("sigaction");
                exit(EXIT_FAILURE);
            }

            rxb_init(&rxb, MAX_REQUEST_SIZE * 2);

            for (;;)
            {
                char username[MAX_REQUEST_SIZE];
                char password[MAX_REQUEST_SIZE];
                char tipologia[MAX_REQUEST_SIZE];
                char nomefile[MAX_REQUEST_SIZE + 256];
                size_t username_len, password_len, tipologia_len;

                memset(&username, 0, sizeof(username));
                username_len = sizeof(username);

                if ((rxb_readline(&rxb, ns, username, &username_len)) < 0)
                {
                    perror("rxb_readline username");
                    exit(EXIT_FAILURE);
                }

#ifdef USE_LIBUNISTRING
                if ((u8_check((uint8_t *)username, username_len)) != NULL)
                {
                    fprintf(stderr, "Username non è in UTF-8\n");
                    close(ns);
                    exit(EXIT_FAILURE);
                }
#endif

                memset(&password, 0, sizeof(password));
                password_len = sizeof(password);

                if ((rxb_readline(&rxb, ns, password, &password_len)) < 0)
                {
                    perror("rxb_readline password");
                    exit(EXIT_FAILURE);
                }

#ifdef USE_LIBUNISTRING
                if ((u8_check((uint8_t *)password, password_len)) != NULL)
                {
                    fprintf(stderr, "Password non è in UTF-8\n");
                    close(ns);
                    exit(EXIT_FAILURE);
                }
#endif

                memset(&tipologia, 0, sizeof(tipologia));
                tipologia_len = sizeof(tipologia);

                if ((rxb_readline(&rxb, ns, tipologia, &tipologia_len)) < 0)
                {
                    perror("rxb_readline tipologia");
                    exit(EXIT_FAILURE);
                }

#ifdef USE_LIBUNISTRING
                if ((u8_check((uint8_t *)username, username_len)) != NULL)
                {
                    fprintf(stderr, "Username non è in UTF-8\n");
                    close(ns);
                    exit(EXIT_FAILURE);
                }
#endif

                if ((autorizza(username, password)) != 1)
                {
                    char *non_autorizza = "Non autorizza\n";
                    write_all(&rxb, non_autorizza, strlen(non_autorizza));
                    write_all(&rxb, end_request, strlen(end_request));
                    continue;
                }

                snprintf(nomefile, sizeof(nomefile), "./toys/%s.txt", tipologia);

                if (pipe(pipe_n1n2) < 0)
                {
                    perror("pipe");
                    exit(EXIT_FAILURE);
                }

                pid1 = fork();

                if (pid1 < 0)
                {
                    perror("fork pid1");
                    exit(EXIT_FAILURE);
                }
                else if (pid1 == 0)
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

                    execlp("grep", "grep", "disponibile", nomefile, (char *)NULL);
                    perror("grep");
                    exit(EXIT_FAILURE);
                }

                pid2 = fork();

                if (pid2 < 0)
                {
                    perror("fork pid2");
                    exit(EXIT_FAILURE),
                }
                else if (pid2 == 0)
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
                    if (dup(ns) < 0)
                    {
                        perror("dup");
                        exit(EXIT_FAILURE);
                    }
                    close(ns);

                    execlp("sort", "sort", "-n", (char *)NULL);
                    perror("execlp sort");
                    exit(EXIT_FAILURE);
                }

                close(pipe_n1n2[0]);
                close(pipe_n1n2[1]);

                waitpid(pid1, &status, 0);
                waitpid(pid2, &status, 0);

                if (write_all(ns, end_request, strlen(end_request)) < 0)
                {
                    perror("write");
                    exit(EXIT_FAILURE);
                }
            }

            close(ns);

            exit(EXIT_SUCCESS);
        }
    }

    close(sd);

    return 0;
}
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include "rxb.h"
#include "utils.h"

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
    int sd, err, on;
    struct addrinfo hints, *res;
    struct sigaction sa;

    if (argc != 2)
    {
        fprintf(stderr, "Errore argomenti! Uso: server bla bla");
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = handler;

    if (sigaction(SIGCHLD, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    if ((err = getaddrinfo(NULL, argv[1], &hints, &res)) != 0)
    {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    if ((sd = socket(sd, res->ai_socktype, res->ai_protocol)) < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    on = 1;

    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    if ((err = bind(sd, res->ai_addr, res->ai_addrlen)) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if ((err = listen(sd, SOMAXCONN)) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        int ns, pid_f;

        if ((ns = accept(sd, NULL, NULL)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if ((pid_f = fork()) < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid_f == 0)
        {
            rxb_t rxb;
            char username[MAX_REQUEST_SIZE];
            char password[MAX_REQUEST_SIZE];
            char categoria[MAX_REQUEST_SIZE];
            size_t username_len, password_len, categoria_len;

            close(sd);

            rxb_init(&rxb, MAX_REQUEST_SIZE * 2);
            signal(SIGCHLD, SIG_DFL);

            while (1)
            {
                char *end_request = "--- END REQUEST ---\n";
                int pid_cut, pid_sort, pid_head, status;
                int pipe_cs[2], pipe_sh[2];

                memset(username, 0, sizeof(username));
                username_len = sizeof(username) - 1;

                err = rxb_readline(&rxb, ns, username, &username_len);
                if (err < 0)
                {
                    perror("rxb_readline username");
                    exit(EXIT_FAILURE);
                }

                memset(password, 0, sizeof(password));
                password_len = sizeof(password) - 1;

                err = rxb_readline(&rxb, ns, password, &password_len);
                if (err < 0)
                {
                    perror("rxb_readline password");
                    exit(EXIT_FAILURE);
                }

                if (autorizza(username, password) != 0)
                {
                    char *non_autorizza = "Non autorizzato\n";
                    write_all(ns, non_autorizza, strlen(non_autorizza));
                    write_all(ns, non_autorizza, strlen(non_autorizza));
                    continue;
                }

                memset(categoria, 0, sizeof(categoria));
                categoria_len = sizeof(categoria) - 1;

                err = rxb_readline(&rxb, ns, categoria, &categoria_len);
                if (err < 0)
                {
                    perror("rxb_readline categoria");
                    exit(EXIT_FAILURE);
                }

                if ((pipe(pipe_cs)) < 0)
                {
                    perror("pipe_cs");
                    exit(EXIT_FAILURE);
                }

                if ((pid_cut = fork()) < 0)
                {
                    perror("pid_cut");
                    exit(EXIT_FAILURE);
                }
                else if (pid_cut == 0)
                {
                    char nomefile[MAX_REQUEST_SIZE + 256];

                    close(ns);
                    close(1);
                    dup(pipe_cs[1]);
                    close(pipe_cs[1]);
                    close(pipe_cs[0]);

                    snprint(nomefile, sizeof(nomefile), "%s.txt", categoria);

                    execlp("cut", "cut", "-d", ","
                                               "-f",
                           "1,3,4", nomefile, (char *)NULL);
                    perror("cut");
                    exit(EXIT_FAILURE);
                }

                if ((pipe(pipe_sh)) < 0)
                {
                    perror("pipe_sh");
                    exit(EXIT_FAILURE);
                }

                if ((pid_sort = fork()) < 0)
                {
                    perror("pid_sort");
                    exit(EXIT_FAILURE);
                }
                else if (pid_sort == 0)
                {
                    close(ns);
                    close(0);
                    dup(pipe_cs[0]);
                    close(pipe_cs[1]);
                    close(pipe_cs[0]);

                    close(1);
                    dup(pipe_sh[1]);
                    close(pipe_sh[0]);
                    close(pipe_sh[1]);

                    execlp("sort", "sort", "-rn", (char *)NULL);
                    perror("sort");
                    exit(EXIT_FAILURE);
                }

                if ((pid_head = fork()) < 0)
                {
                    perror("pid_head");
                    exit(EXIT_FAILURE);
                }
                else if (pid_head == 0)
                {
                    close(pipe_cs[0]);
                    close(pipe_cs[1]);

                    close(0);
                    dup(pipe_sh[1]);
                    close(pipe_sh[0]);

                    close(1);
                    dup(ns);
                    close(ns);

                    execlp("head", "head", "-n", "10", (char *)NULL);
                    perror("head");
                    exit(EXIT_FAILURE);
                }

                close(pipe_cs[1]);
                close(pipe_cs[0]);
                close(pipe_sh[1]);
                close(pipe_sh[0]);

                waitpid(pid_cut, &status, 0);
                waitpid(pid_sort, &status, 0);
                waitpid(pid_head, &status, 0);

                write_all(ns, end_request, strlen(end_request));
            }

            close(ns);
            rxb_destroy(&rxb);
            exit(EXIT_SUCCESS);
        }

        close(ns);
    }

    close(sd);

    return 0;
}
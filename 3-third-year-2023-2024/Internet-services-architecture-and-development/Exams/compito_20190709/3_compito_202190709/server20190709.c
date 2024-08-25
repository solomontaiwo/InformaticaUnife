#define _POSIX_C_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <unistd.h>
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
    int err, sd, on;
    struct addrinfo hints, *res;
    struct sigaction sa;

    if (argc != 2)
    {
        fprintf(stderr, "Uso: server20190709 ...");
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    err = getaddrinfo(argv[1], argv[2], &hints, &res);

    if (err < 0)
    {
        fprintf(stderr, "Errore getaddrinfo");
        exit(EXIT_FAILURE);
    }

    sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (sd < 0)
    {
        fprintf(stderr, "Errore socket");
        exit(EXIT_FAILURE);
    }

    err = bind(sd, res->ai_addr, res->ai_addrlen);

    if (err < 0)
    {
        fprintf(stderr, "Errore bind");
        exit(EXIT_FAILURE);
    }

    err = listen(sd, SOMAXCONN);

    if (err < 0)
    {
        fprintf(stderr, "Errore listen");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        int ns, pid_f;

        ns = accept(sd, NULL, NULL);
        if (ns < 0)
        {
            fprintf(stderr, "Errore accept");
            exit(EXIT_FAILURE);
        }

        pid_f = fork();

        if (pid_f < 0)
        {
            perror("Errore fork");
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
                username_len = sizeof(username_len);
                err = rxb_readline(&rxb, ns, username, &username_len);

                if (err < 0)
                {
                    exit(EXIT_FAILURE);
                }

                memset(password, 0, sizeof(password));
                password_len = sizeof(password_len);
                err = rxb_readline(&rxb, ns, password, &password_len);

                if (autorizza(username, password) != 1)
                {
                    char *non_autorizzato = "Non autorizzato\n";
                    write_all(ns, non_autorizzato, strlen(non_autorizzato));
                    write_all(ns, end_request, strlen(end_request));
                    continue;
                }

                if ((pipe(pipe_cs)) < 0)
                {
                    exit(EXIT_FAILURE);
                }

                pid_cut = fork();

                if (pid_cut < 0)
                {
                    exit(EXIT_FAILURE);
                }
                else if (pid_cut == 0)
                {
                    char nomefile[MAX_REQUEST_SIZE + 256];

                    close(ns);
                    close(1);
                    dup(pipe_cs[1]);
                    close(pipe_cs[0]);

                    snprint(nomefile, sizeof(nomefile), "%s.txt", categoria);

                    execlp("cut", "cut", "-d", ",", "-f", "1,3,4", nomefile, (char *)NULL);
                    perror("cut");
                    exit(EXIT_FAILURE);
                }

                if (pipe_sh < 0)
                {
                    exit(EXIT_FAILURE);
                }

                pid_sort = fork();

                if (pid_sort < 0)
                {
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
                    close(pipe_sh[1]);
                    close(pipe_sh[0]);

                    execlp("sort", "sort", "-rn", (char *)NULL);
                    perror("exec");
                    exit(EXIT_FAILURE);
                }

                pid_head = fork();

                if (pid_head < 0)
                {
                    exit(EXIT_FAILURE);
                }
                else if (pid_head == 0)
                {
                    close(ns);
                    close(pipe_cs[1]);
                    close(pipe_cs[0]);

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

                close(pipe_cs[0]);
                close(pipe_cs[1]);
                close(pipe_sh[0]);
                close(pipe_sh[1]);

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
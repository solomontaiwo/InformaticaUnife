// interfaccia trova_vini cantina-1 ... cantina-N
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX 20
#define N 256

void handler(int s)
{
    int status;
    wait(&status);
}

int main(int argc, char **argv)
{
    int pid, pid_n1, pid_n2;
    int ncantine, i, nread;
    int pip0[MAX][2], n1n2[2], n2p1[2];
    char buffer[N], buff[N];

    signal(SIGINT, SIG_IGN);
    signal(SIGCHLD, handler);

    if (argc < 2)
    {
        fprintf(stderr, "Uso: ./trova_vini cantina1 ... cantinaN\n");
        exit(1);
    }

    ncantine = argc - 1;
    if (ncantine > MAX)
    {
        fprintf(stderr, "Inserire al massimo %d cantine!\n", MAX);
        exit(1);
    }

    printf("Inserire il vino da cercare:\n");
    scanf("%s", buffer);
    while (strcmp(buffer, "fine"))
    {
        for (i = 0; i < ncantine; i++)
        {
            if (pipe(pip0[i]) < 0)
            {
                perror("errore pipe");
                exit(2);
            }

            if ((pid = fork()) < 0)
            {
                perror("Errore fork");
                exit(3);
            }

            if (pid == 0)
            {
                if (pipe(n1n2) < 0)
                {
                    perror("errore pipe 1");
                    exit(4);
                }

                if (pipe(n2p1) < 0)
                {
                    perror("errore pipe 2");
                    exit(5);
                }

                if ((pid_n1 = fork()) < 0)
                {
                    perror("errore fork nipote 1");
                    exit(6);
                }

                if (pid_n1 == 0)
                {
                    close(n2p1[0]);
                    close(n2p1[1]);

                    close(1);
                    dup(n1n2[1]);

                    close(n1n2[1]);
                    close(n1n2[0]);
                    execlp("grep", "grep", "disponibile", argv[i + 1], (char *)0);
                    perror("errore grep 1");
                    exit(7);
                }

                if (pid_n1 > 0)
                {
                    if ((pid_n2 = fork()) < 0)
                    {
                        perror("Errore fork nipote 2");
                        exit(8);
                    }

                    if (pid_n2 == 0)
                    {
                        close(0);
                        dup(n1n2[0]);
                        close(n1n2[0]);
                        close(n1n2[1]);
                        close(1);
                        dup(n2p1[1]);
                        close(n2p1[1]);
                        close(n2p1[0]);

                        execlp("grep", "grep", buffer, (char *)0);
                        perror("errore grep 2");
                        exit(9);
                    }

                    if (pid_n2 > 0)
                    {
                        close(n1n2[0]);
                        close(n1n2[1]);
                        close(1);
                        dup(pip0[i][0]);
                        close(pip0[i][0]);
                        close(pip0[i][1]);
                        execlp("sort", "sort", "-n", (char *)0);
                        perror("Errore sort");
                        exit(10);
                    }
                }
            }
            if (pid > 0)
            {
                close(pip0[i][1]);
            }
        }
        for (i = 0; i < ncantine; i++)
        {
            printf("%s:\n", argv[i + 1]);
            while ((nread = read(pip0[i][0], buff, N)) > 0)
            {
                write(1, buff, nread);
            }
            close(pip0[i][0]);
        }

        printf("inserire il vino da cercare:\n");
        scanf("%s", buffer);
    }
    return 0;
}
// interfaccia: ricercaFile Timeout S1 S2 ... Sn
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define SIZE 80

static volatile sig_atomic_t timeout;

void handler()
{
    printf("Ricevuto ctrl-C, timeout e terminazione"\n);
    alarm(timeout);
}

void gestore_alarm()
{
    printf("Terminazione \n");
    kill(0, SIGKILL);
}

int main(int argc, char **argv)
{
    int i, j, status, nread, Nproc, p0pi[SIZE][2], pip0[SIZE][2];
    char buff[SIZE], nomefile[SIZE];

    signal(SIGINT, handler);
    signal(SIGALRM, gestore_alarm);

    Nproc = argc - 2;
    timeout = atoi(argv[1]);

    for (i = 0; i < Nproc; i++)
    {
        pipe(p0pi[i]);
        pipe(pip0[i]);
    }

    for (i = 0; i < Nproc; i++)
    {
        if (fork() == 0)
        {
            signal(SIGINT, SIG_IGN);
            signal(SIGALRM, SIG_IGN);

            for (j = 0; j < Nproc; j++)
            {
                if (j != i)
                {
                    close(p0pi[j][0]);
                    close(p0pi[j][1]);
                    close(pip0[j][0]);
                    close(pip0[j][1]);
                }
                close(p0pi[i][1]);
                close(pip0[i][0]);
            }

            while (1)
            {
                nread = read(p0pi[i][0], nomefile, SIZE);
                if (fork() == 0)
                {
                    close(1);
                    dup(pip0[i][1]);
                    close(pip0[i][1]);
                    close(p0pi[i][0]);

                    execlp("grep", "grep", "-c", argv[i + 2], nomefile, (char *)0);
                }
                wait(&status);
            }
            exit(1);
        }
    }

    for (i = 0; i < Nproc; i++)
    {
        close(p0pi[i][0]);
        close(pip0[i][1]);
    }
    while (1)
    {
        printf("Inserire il nome del file:\n");
        scanf("%s", nomefile);
        for (i = 0; i < Nproc; i++)
        {
            write(p0pi[i][1], nomefile, strlen(nomefile) + 1);

            for (i = 0; i < Nproc; i++)
            {
                nread = read(pip0[i][0], buff, SIZE);
                buff[nread - 1] = '\0';
                printf("Padre: la stringa 5s compare nel file %s %s volte\n", argv[i + 2], nomefile, buff);
            }
        }
    }
}
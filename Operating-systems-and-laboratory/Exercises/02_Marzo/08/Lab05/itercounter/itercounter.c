#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_NUM_PROC 20

// interfaccia: itercounter Nf Nsec

int contatore = 0;

void gestore(int signo)
{
    printf("Il processo %d ha eseguito %d interazioni per il segnale %d\n", getpid(), contatore, signo);
    exit(0);
}

int main(int argc, char **argv)
{
    int fd, status, *pid, i;

    if (argc != 3)
    {
        fprintf(stderr, "Errore argomenti: uso %s <Nf> <Nsec>\n", argv[0]);
        exit(1);
    }

    int Nf = atoi(argv[1]);
    if (Nf <= 0)
    {
        fprintf(stderr, "Errore, \"%s\" non è un numero positivo o maggiore di zero\n", argv[1]);
        exit(2);
    }
    else if (Nf > MAX_NUM_PROC)
    {
        fprintf(stderr, "Il parametro <Nf> non può essere maggiore di %d\n", MAX_NUM_PROC);
        exit(3);
    }

    int Nsec = atoi(argv[2]);
    if (Nsec <= 0)
    {
        fprintf(stderr, "Errore, \"%s\" non è un numero positivo o maggiore di zero\n", argv[2]);
        exit(4);
    }

    pid = (int *)malloc(Nf * sizeof(int));

    for (i = 0; i < Nf; i++)
    {
        pid[i] = fork();
        if (pid[i] < 0)
        {
            perror("Errore nella fork\n");
            exit(5);
        }

        if (pid[i] == 0)
        {
            struct sigaction sa;
            sigemptyset(&sa.sa_mask);
            sa.sa_flags = 0;
            sa.sa_handler = gestore;
            if (sigaction(SIGUSR1, &sa, NULL) < 0)
            {
                perror("Errore in sigaction, SIGUSR1 figlio");
                exit(-3);
            }

            while (1)
            {
                sleep(1);
                contatore++;
            }
        }
    }

    sleep(Nsec);

    for (i = 0; i < Nf; i++)
    {
        kill(pid[i], SIGUSR1);
    }

    free(pid);

    for (i = 0; i < Nf; i++)
    {
        wait(&status);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

#define MAX_PROC_NUM 20

int contatore = 0;

void gestore(int signo)
{
    printf("Il processo %d ha eseguito %d iterazioni per il segnale %d\n", getpid(), contatore, signo);
    exit(0);
}

int main(int argc, char **argv)
{
    int *pid;
    int Nf, Nsec, i, status;

    if (argc != 3)
    {
        fprintf(stderr, "Uso: %s <num_processi> <num_secondi>\n", argv[1]);
        exit(1);
    }

    Nf = atoi(argv[1]);

    if (Nf <= 0)
    {
        fprintf(stderr, "Il parametro <num_processi> deve essere un intero positivo\n");
        exit(2);
    }
    else if (Nf > MAX_PROC_NUM)
    {
        fprintf(stderr, "Il parametro <num_processi> non può essere maggiore di %d\n", MAX_PROC_NUM);
        exit(3);
    }

    Nsec = atoi(argv[2]);
    if (Nsec <= 0)
    {
        fprintf(stderr, "Il parametro <num_secondi> deve essere un intero positivo\n");
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
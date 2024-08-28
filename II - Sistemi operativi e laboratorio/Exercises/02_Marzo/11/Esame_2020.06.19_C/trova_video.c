// interfaccia: trova_video dir
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define DIM 100

static volatile sig_atomic_t counter = 0;

void handler(int signal)
{
    printf("\nCTRL-C ricevuto:\t Sono state servite %d richieste\n", counter);
    exit(0);
}

int main(int argc, char **argv)
{
    char argomento[20], data[9], to_open[DIM];
    int pid1, pid2, fd, status;
    int pipe_sort[2];

    if (argc != 2)
    {
        fprintf(stderr, "Errore: uso %s dir\n", argv[0]);
        exit(1);
    }

    if (argv[1][0] == '/')
    {
        fprintf(stderr, "Errore: dir deve essere un nome relativo di directory");
        exit(2);
    }

    if ((fd = open(argv[1], O_DIRECTORY)) < 0)
    {
        perror("Errore nell'apertura di dir");
        exit(3);
    }
    close(fd);

    signal(SIGINT, handler);

    while (1)
    {
        printf("Inserire tipo video:\n");
        scanf("%s", argomento);
        printf("Inserire data in formato YYYYMM:\n");
        scanf("%s", data);

        sprintf(to_open, "%s/%s.txt", argv[1], data);

        if ((fd = open(to_open, O_RDONLY)) < 0)
        {
            fprintf(stderr, "Errore nell'apertura del file %s\n", to_open);
            exit(4);
        }
        close(fd);

        if (pipe(pipe_sort) < 0)
        {
            perror("Errore pipe");
            exit(5);
        }

        if ((pid1 = fork()) < 0)
        {
            perror("Errore fork P1");
            exit(6);
        }

        if (pid1 == 0)
        {
            close(pipe_sort[0]);

            close(1);
            dup(pipe_sort[1]);
            close(pipe_sort[1]);

            execlp("grep", "grep", argomento, to_open, (char *)0);
            perror("Errore grep");
            exit(7);
        }

        if ((pid2 = fork()) < 0)
        {
            perror("Errore fork P2");
            exit(8);
        }

        if (pid2 == 0)
        {
            close(pipe_sort[1]);

            close(0);
            dup(pipe_sort[0]);
            close(pipe_sort[0]);

            execlp("sort", "sort", "-r", "-n", (char *)0);
            perror("Errore sort");
            exit(9);
        }

        close(pipe_sort[0]);
        close(pipe_sort[1]);
        wait(&status);
        wait(&status);
        counter++;
    }
    return 0;
}
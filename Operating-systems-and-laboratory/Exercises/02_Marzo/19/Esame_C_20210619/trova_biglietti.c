// interfaccia: trova_biglietti destinazione N
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>

#define DIM 200
#define DIR "/Users/solomontaiwo/Documents/Sistemi-operativi/Esercizi/02_Marzo/19/Esame_C_20210619"

static volatile sig_atomic_t numero_richieste = 0;

void ctrlHandler()
{
    printf("Numero richieste servite: %d\n", numero_richieste);
    exit(0);
}

int main(int argc, char **argv)
{
    int fd, status, pid, p1p2[2], p2p3[2], gg, mm, yyyy, n_offerte;
    char data[DIM], filepath[DIM];

    if (argc != 3)
    {
        fprintf(stderr, "Errore argomenti: uso %s <destinazione> <N>\n", argv[0]);
        exit(1);
    }

    if (argv[1][0] == '/')
    {
        fprintf(stderr, "Errore: <destinaziione> deve essere una stringa\n");
        exit(2);
    }

    if ((n_offerte = atoi(argv[2])) <= 0)
    {
        fprintf(stderr, "Errore: <N> deve essere un numero intero positivo\n");
        exit(3);
    }

    sprintf(filepath, "%s/%s.txt", DIR, argv[1]);

    if ((fd = open(filepath, O_RDONLY)) < 0)
    {
        fprintf(stderr, "Errore: impossibile aprire il file %s\n", filepath);
        exit(4);
    }
    close(fd);

    signal(SIGINT, ctrlHandler);

    while (1)
    {
        printf("Inserire giorno, mese e anno della data di partenza (DDMMYYYY): ");
        scanf("%d %d %d", &gg, &mm, &yyyy);

        if (gg == -1 || mm == -1 || yyyy == -1)
            break;

        sprintf(data, "%02d%02d%04d", gg, mm, yyyy);

        if (pipe(p1p2) < 0)
        {
            perror("P0: errore pipe p1p2");
            exit(5);
        }

        if ((pid = fork()) < 0)
        {
            perror("P0: errore fork P1");
            exit(6);
        }

        if (pid == 0)
        {
            // codice P1
            signal(SIGINT, SIG_DFL);

            close(p1p2[0]);

            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("grep", "grep", data, filepath, (char *)0);
            perror("P1: errore grep");
            exit(7);
        }

        if (pipe(p2p3) < 0)
        {
            perror("P0: errore pipe p2p3");
            exit(8);
        }

        if ((pid = fork()) < 0)
        {
            perror("P0: errore fork P2");
            exit(9);
        }

        if (pid == 0)
        {
            // codice P2
            signal(SIGINT, SIG_DFL);

            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            close(1);
            dup(p2p3[1]);
            close(p2p3[1]);

            execlp("sort", "sort", "-n", (char *)0);
            perror("P2: errore sort");
            exit(10);
        }

        if ((pid = fork()) < 0)
        {
            perror("P0: errore fork P3");
            exit(11);
        }

        if (pid == 0)
        {
            // codice P3
            signal(SIGINT, SIG_DFL);
            char str_n[DIM];
            sprintf(str_n, "%d", n_offerte);

            close(0);
            dup(p2p3[0]);
            close(p2p3[0]);

            execlp("head", "head", "-n", str_n, (char *)0);
            perror("P3: errore head");
            exit(12);
        }

        close(p1p2[0]);
        close(p1p2[1]);
        close(p2p3[0]);
        close(p2p3[1]);

        wait(&status);
        wait(&status);
        wait(&status);

        numero_richieste++;
    }
    printf("Numero richieste servite: %d\n", numero_richieste);
    return 0;
}
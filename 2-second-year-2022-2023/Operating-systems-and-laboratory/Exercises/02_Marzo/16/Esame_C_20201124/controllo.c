// interfaccia controllo dir
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define SIZE 80

static volatile sig_atomic_t byte_ricevuti = 0;

void handler()
{
    printf("Byte totali ricevuti: %d\n", byte_ricevuti);
    exit(0);
}

int main(int argc, char **argv)
{
    int fd, pid1, pid2, status, p1p2[2], p2p0[2];
    char cognome[SIZE], libro[SIZE], filepath[SIZE], buff;

    if (argc != 2)
    {
        fprintf(stderr, "Errore argomenti: uso %s <dir>\n", argv[0]);
        exit(1);
    }

    if (argv[1][0] != '/')
    {
        fprintf(stderr, "Errore: <dir> non è un direttorio assoluto\n");
        exit(2);
    }

    signal(SIGINT, handler);

    fd = open(argv[1], O_DIRECTORY);

    if (fd < 0)
    {
        fprintf(stderr, "Errore nell0'apertura della directory %s\n", argv[1]);
        exit(3);
    }
    close(fd);

    printf("Inserisci il cognome da ricercare: ");
    scanf("%s", cognome);

    printf("Inserisci il libro di interesse: ");
    scanf("%s", libro);

    while ((strcmp(cognome, "fine")) != 0 && (strcmp(libro, "fine")) != 0)
    {
        if (pipe(p1p2) < 0)
        {
            perror("P0: errore pipe p1p2");
            exit(4);
        }

        if (pipe(p2p0) < 0)
        {
            perror("P0: errore pipe p2p0");
            exit(5);
        }

        pid1 = fork();

        if (pid1 < 0)
        {
            perror("P0: errore fork P1");
            exit(6);
        }

        if (pid1 == 0)
        {
            sprintf(filepath, "%s/%s/%s.txt", argv[1], libro, cognome);
            printf("File da cercare: %s\n", filepath);
            fd = open(filepath, O_RDONLY);

            if (fd < 0)
            {
                perror("Non esiste il file corrispondente");
                continue;
            }
            close(fd);

            close(p1p2[0]);

            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("sort", "sort", filepath, (char *)0);
            perror("P1: errore sort");
            exit(7);
        }

        pid2 = fork();

        if (pid2 < 0)
        {
            perror("P0: errore fork P2");
            exit(8);
        }

        if (pid2 == 0)
        {
            close(p1p2[1]);

            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            close(p2p0[0]);

            close(1);
            dup(p2p0[1]);
            close(p2p0[1]);

            execlp("grep", "grep", "ingresso", (char *)0);
            perror("P2: errore grep");
            exit(9);
        }

        close(p1p2[0]);
        close(p1p2[1]);
        wait(&status);

        close(p2p0[1]);

        int byte_ricerca = 0;

        memset(buff, 0, SIZE);

        while ((byte_ricerca = read(p2p0[0], buff, sizeof(buff))) > 0)
        {
            write(1, buff, byte_ricerca);
            byte_ricevuti += byte_ricerca;
            memset(buff, 0, SIZE);
        }

        close(p2p0[0]);
        wait(&status);

        printf("Inserisci il cognome da ricercare: ");
        scanf("%s", cognome);

        printf("Inserisci il libro di interesse: ");
        scanf("%s", libro);
    }

    printf("Numero totale di byte letti da P2: %d\n", byte_ricevuti);

    return 0;
}
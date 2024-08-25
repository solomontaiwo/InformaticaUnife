// interfaccia: controllo dir
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#define DIM 50
#define DIM_PATH 200
#define BUFDIM 256

static volatile sig_atomic_t byte_ricevuti = 0;

void handler()
{
    printf("Quantità di byte ricevuti: %d\n", byte_ricevuti);
    exit(0);
}

int main(int argc, char **argv)
{
    int fd, status, p1p2[2], p2p0[2], pid;
    char cognome[DIM], nome_libro[DIM], filepath[DIM_PATH], buff[BUFDIM];

    if (argc != 2)
    {
        fprintf(stderr, "Errore argomenti: uso %s <dir>\n", argv[0]);
        exit(1);
    }

    if (argv[1][0] != '/')
    {
        fprintf(stderr, "Errore: <dir> deve essere un nome assoluto\n");
        exit(2);
    }

    if ((fd = open(argv[1], O_DIRECTORY)) < 0)
    {
        fprintf(stderr, "Errore: <dir> non è un direttorio\n");
        exit(3);
    }
    close(fd);

    signal(SIGINT, handler);

    printf("Inserisci un cognome: ");
    scanf("%s", cognome);

    prints("Inserisci il nome di un libro: ");
    scanf("%s", nome_libro);

    while ((strcmp(cognome, "esci")) != 0 || strcmp(nome_libro, "esci") != 0)
    {
        if ((pipe(p1p2)) < 0)
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

            sprintf(filepath, "%s/%s/%s", argv[1], nome_libro, cognome);

            if ((fd = open(filepath, O_RDONLY)) < 0)
            {
                fprintf("Errore: impossibile aprire file %s.txt\n", filepath);
                exit(4);
            }
            close(fd);

            close(p1p2[0]);

            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("sort", "sort", filepath, (char *)0);
            perror("P1: errore sort");
            exit(5);
        }

        if ((pipe(p2p0)) < 0)
        {
            perror("P0: errore pipe p2p0");
            exit(5);
        }

        if ((pid = fork()) < 0)
        {
            perror("P0: errore fork P2");
            exit(6);
        }

        if (pid == 0)
        {
            // codice P2
            close(p1p2[1]);

            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            close(1);
            dup(p2p0[1]);
            close(p2p0[1]);

            execlp("grep", "grep", "ingresso", (char *)0);
            perror("P1: errore grep");
            exit(7);
        }

        close(p1p2[0]);
        close(p1p2[1]);
        wait(&status);

        close(p2p0[1]);

        int byte_ricerca = 0;

        memset(buff, 0, BUFDIM);
        while (byte_ricerca = read(p2p0[0], buff, sizeof(buff)) > 0)
        {
            write(1, buff, byte_ricerca);
            byte_ricevuti += byte_ricerca;
            memset(buff, 0, BUFDIM);
        }

        close(p2p0[0]);
        wait(&status);

        printf("Inserisci un cognome: ");
        scanf("%s", cognome);

        prints("Inserisci il nome di un libro: ");
        scanf("%s", nome_libro);
    }

    printf("Quantità di byte ricevuti: %d\n", byte_ricevuti);
    return 0;
    
}
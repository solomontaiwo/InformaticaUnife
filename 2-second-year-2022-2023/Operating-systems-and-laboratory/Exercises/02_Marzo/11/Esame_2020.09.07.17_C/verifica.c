// interfaccia verifica fileBollette
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#define SIZE 1024

static volatile sig_atomic_t numero_richieste = 0;

void handler()
{
    printf("Arrivato CTRL-C. Numero di richieste eseguite: %d\n", numero_richieste);
    exit(0);
}

int main(int argc, char **argv)
{
    int status, pid1, pid2, pid3, fd;
    char tipologia[SIZE];
    int p1p2[2], p2p3[2];

    if (argc < 2)
    {
        perror("Uso corretto: ./verifica <fileBollette>\n");
        exit(1);
    }

    if ((fd = open(argv[1], O_RDONLY)) < 0)
    {
        perror("Il file non esiste\n");
        exit(2);
    }
    close(fd);

    signal(SIGINT, handler);

    printf("Inserisci tipologia: \n");
    scanf("%s", tipologia);

    while (strcmp(tipologia, "fine") != 0)
    {
        if (pipe(p1p2) < 0)
        {
            perror("Pipe");
            exit(3);
        }

        pid1 = fork();
        if (pid1 < 0)
        {
            perror("Fork P1");
            exit(4);
        }

        if (pid1 == 0)
        {
            close(1);
            dup(p1p2[1]);
            close(p1p2[0]);
            close(p1p2[1]);

            execlp("grep", "grep", tipologia, argv[1], (char *)0);
            perror("grep 1");
            exit(5);
        }

        close(p1p2[1]);

        if (pipe(p2p3) < 0)
        {
            perror("pipe");
            exit(6);
        }

        pid2 = fork();
        if (pid2 < 0)
        {
            perror("Fork P2");
            exit(7);
        }

        if (pid2 == 0)
        {
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            close(1);
            dup(p2p3[1]);

            close(p2p3[0]);
            close(p2p3[1]);

            execlp("grep", "grep", "da pagare", (char *)0);
            perror("Grep 2");
            exit(8);
        }

        close(p1p2[0]);
        close(p2p3[1]);

        pid3 = fork();
        if (pid3 < 0)
        {
            perror("Errore P3");
            exit(9);
        }

        if (pid3 == 0)
        {
            close(0);
            dup(p2p3[0]);
            close(p2p3[0]);
            execlp("sort", "sort", "-n", "-r", (char *)0);
            perror("sort");
            exit(10);
        }

        close(p2p3[0]);

        wait(&status);
        wait(&status);
        wait(&status);

        numero_richieste++;

        printf("Inserisci tipologia:\n");
        scanf("%s", tipologia);
    }
    printf("Fine applicazione, svolti %d servizi\n", numero_richieste);
}
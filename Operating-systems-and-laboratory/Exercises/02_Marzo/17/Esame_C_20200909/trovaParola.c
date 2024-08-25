// interfaccia trovaParola fileAnagrafica
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

#define DIM 50

static volatile sig_atomic_t numero_ricerche = 0;

void ctrlHandler()
{
    printf("Il numero di ricerche effettuate è pari a %d\n", numero_ricerche);
    exit(0);
}

int main(int argc, char **argv)
{
    int fd, status, pid1, pid2, p1p2[2], prefisso;
    char cognome[DIM], prefisso[DIM];

    if (argc != 2)
    {
        fprintf(stderr, "Errore argomenti: uso %s <fileAnagrafica>\n", argv[0]);
        exit(1);
    }

    if (argv[1][0] != '/')
    {
        fprintf(stderr, "Errore: <fileAnagrafica> deve essere un nome assoluto\n");
        exit(2);
    }

    if ((fd = open(argv[1], O_RDONLY)) < 0)
    {
        fprintf("Errore: impossibile aprire il file %s\n", argv[1]);
        exit(3);
    }
    close(fd);

    signal(SIGINT, ctrlHandler);

    printf("Inserire un cognome: ");
    scanf("%s", cognome);

    printf("Inserire un prefisso telefonico: ");
    scanf("%s", prefisso);

    while (strcmp(cognome, "fine") != 0 || strcmp(prefisso, "fine") != 0)
    {
        if (pipe(p1p2) < 0)
        {
            perror("P0: errore pipe p1p2");
            exit(4);
        }

        if ((pid1 = fork()) < 0)
        {
            perror("P0: errore pid1");
            exit(5);
        }

        if (pid1 == 0)
        {
            // codice P1
            close(p1p2[0]);
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("grep", "grep", cognome, argv[1], (char *)0);
            perror("P1: errore grep");
            exit(6);
        }

        if ((pid2 = fork()) < 0)
        {
            perror("P0: errore pid2");
            exit(7);
        }

        if (pid2 == 0)
        {
            // codice P2
            close(p1p2[1]);

            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            execlp("grep", "grep", prefisso, (char *)0);
            perror("P2: errore grep");
            exit(8);
        }

        close(p1p2[0]);
        close(p1p2[1]);

        wait(&status);
        wait(&status);

        numero_ricerche++;

        printf("Inserire un cognome: ");
        scanf("%s", cognome);

        printf("Inserire un prefisso telefonico: ");
        scanf("%s", prefisso);
    }

    printf("Il numero di ricerche effettuate è pari a %d\n", numero_ricerche);
    return 0;
}
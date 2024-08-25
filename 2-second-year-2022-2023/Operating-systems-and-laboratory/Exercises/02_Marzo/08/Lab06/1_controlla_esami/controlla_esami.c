// interfaccia: controlla_esami file_dati

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define DIM 80

int main(int argc, char **argv)
{
    int p1p2[2];
    char matricola[DIM];
    int pid1, pid2, fd, status;

    if (argc != 2)
    {
        fprintf(stderr, "Errore. Uso %s <file_dati>\n", argv[0]);
        exit(1);
    }

    if (argv[1][0] != '/')
    {
        fprintf(stderr, "Il primo argomento deve essere un nome assoluto di file\n");
        exit(2);
    }

    if ((fd = open(argv[1], O_RDONLY)) < 0)
    {
        fprintf(stderr, "Il file %s non esiste\n", argv[1]);
        exit(3);
    }

    close(fd);

    printf("Inserisci la matricola da cercare: ");
    scanf("%s", matricola);

    while (strcmp(matricola, "fine"))
    {
        // Creazione della pipe
        if (pipe(p1p2) < 0)
        {
            perror("Errore pipe p1 --> p2\n");
            exit(4);
        }

        // Genero P1
        if ((pid1 = fork()) < 0)
        {
            perror("Errore fork p1\n");
            exit(5);
        }

        if (pid1 == 0)
        {
            // Chiusura canale non necessario, quello di lettura
            close(p1p2[0]);

            // Redirezione stdout
            close(1);
            dup(p1p2[1]);   // duplicazione lato scrittura della pipe del padre
            close(p1p2[1]); // chiusura lato scrittura pipe appena duplicato

            // exec()
            execlp("grep", "grep", matricola, argv[1], (char *)0);
            perror("Errore execlp grep");
            exit(6);
        }

        if ((pid2 = fork()) < 0)
        {
            perror("Errore nella fork p2\n");
            exit(7);
        }

        if (pid2 == 0)
        {
            // Chiudo il canale di scrittura non necessario
            close(p1p2[1]);

            // Redirezione stdin, sostituito dal lato in lettura della pipe
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            execlp("wc", "wc", "-l", (char *)0);
            perror("Errore execlp wc\n");
            exit(8);
        }

        // P0 padre, chiudo i canali non necessari
        close(p1p2[0]);
        close(p1p2[1]);

        // Attendo la morte dei figli
        close(p1p2[0]);
        close(p1p2[1]);

        // Chiedo una nuova matricola
        printf("Inserisci la matricola da cercare: ");
        scanf("%s", matricola);
    }

    return 0;
}
// interfaccia: trovaParola fileAnagrafica
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define DIM 80

static volatile sig_atomic_t contatore_richieste = 0;

void handler(int signo)
{
    printf("Sono state eseguite %d richieste, termino\n", contatore_richieste);
    exit(0);
}

int main(int argc, char **argv)
{
    int fd, p1, p2, status, p1p2[2];
    char cognome[DIM];
    char prefisso[DIM];

    if (argc != 2)
    {
        fprintf(stderr, "Errore: uso %s <fileAnagrafica>\n", argv[0]);
        exit(-1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "Errore nell'apertura del file %s\n", argv[1]);
        exit(-2);
    }
    close(fd);

    signal(SIGINT, handler);

    while (1)
    {
        printf("Inserisci il cognome da ricercare:\n");
        scanf("%s", cognome);
        if (!strcmp(cognome, "fine"))
            break;

        printf("Inserisci il prefisso di interesse:\n");
        scanf("%s", prefisso);

        if (pipe(p1p2) < 0)
        {
            perror("Errore pipe() p1p2");
            exit(-3);
        }

        p1 = fork();
        if (p1 < 0)
        {
            perror("Errore fork p1");
            exit(-4);
        }

        if (p1 == 0)
        {
            close(p1p2[0]);

            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("grep", "grep", cognome, argv[1], (char *)0);
            perror("Errore grep p1");
            exit(-5);
        }

        p2 = fork();
        if (p2 < 0)
        {
            perror("Errore fork() p2");
            exit(-6);
        }

        if (p2 == 0)
        {
            close(p1p2[1]);

            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            execlp("grep", "grep", prefisso, (char *)0);
            perror("Errore grep prefisso");
            exit(-6);
        }

        close(p1p2[0]);
        close(p1p2[1]);
        wait(&status);
        wait(&status);
        contatore_richieste++;
    }

    printf("Servite %d richieste, termino\n", contatore_richieste);

    return 0;
}

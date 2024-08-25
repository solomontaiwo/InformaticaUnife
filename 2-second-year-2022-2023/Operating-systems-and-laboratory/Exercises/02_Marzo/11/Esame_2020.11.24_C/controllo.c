// interfaccia: controllo dir
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>

#define DIM 80
#define BUFDIM 256

static volatile sig_atomic_t byte_p2 = 0;

void handler()
{
    printf("Byte letti dal processo P2: %d\n", byte_p2);
    exit(0);
}

int main(int argc, char **argv)
{
    int fd, p1, p2, p1p2[2], p2p0[2], status;
    char cognome[DIM], libro[DIM], buff[BUFDIM];

    if (argc != 2)
    {
        fprintf(stderr, "%s <dir> \n", argv[0]);
        exit(-1);
    }

    if (argv[1][0] != '/')
    {
        fprintf(stderr, "%s deve avere path assoluta\n", argv[1]);
        exit(-2);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "Errore apertura della directory %s\n", argv[1]);
        exit(-3);
    }
    close(fd);

    signal(SIGINT, handler);

    printf("Inserisci il cognome da ricercare:\n");
    scanf("%s", cognome);

    printf("Inserisci il libro di interesse:\n");
    scanf("%s", libro);

    while ((strcmp(cognome, "fine") != 0) && (strcmp(libro, "fine") != 0))
    {
        if (pipe(p1p2) < 0)
        {
            perror("Errore pipe p1p2");
            exit(-4);
        }

        p1 = fork();
        if (p1 < 0)
        {
            perror("Errore fork() p1");
            exit(-5);
        }

        if (p1 == 0)
        {
            char path_libro[128];
            sprintf(path_libro, "%s/%s/%s", argv[1], libro, cognome);
            printf("File da ricercare %s\n", path_libro);

            fd = open(path_libro, O_RDONLY);
            if (fd < 0)
            {
                perror("Non esiste un file corrispondente");
                continue;
            }
            close(fd);

            close(p1p2[0]);

            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("sort", "sort", path_libro, (char *)0);
            perror("Errore sort p1");
            exit(-6);
        }

        if (pipe(p2p0) < 0)
        {
            perror("Errore creazione pipe p2p0");
            exit(-7);

            p2 = fork();
            if (p2 < 0)
            {
                perror("Errore fork() p2");
                exit(-8);
            }

            if (p2 == 0)
            {
                close(p2p0[1]);

                close(0);
                dup(p1p2[0]);
                close(p1p2[0]);

                close(p2p0[0]);

                close(1);
                dup(p2p0[1]);
                close(p2p0[1]);

                execlp("grep", "grep", "ingresso", (char *)0);
                perror("Errore grep P2");
                exit(-9);
            }

            close(p1p2[0]);
            close(p1p2[1]);
            wait(&status);

            close(p2p0[1]);

            int byte_ricerca = 0;

            memset(buff, 0, BUFDIM);
            while ((byte_ricerca = read(p2p0[0], buff, sizeof(buff))) > 0)
            {
                write(1, buff, byte_ricerca);
                byte_p2 += byte_ricerca;
                memset(buff, 0, BUFDIM);
            }

            close(p2p0[0]);
            wait(&status);

            printf("Inserisci il cognome da ricercare:\n");
            scanf("%s", cognome);

            printf("Inserisci il libro di interesse\n");
            scanf("%s", libro);
        }
        printf("Numero totale di byte letti da P2: %d\n", byte_p2);
    }
}
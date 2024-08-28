#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>

#define HOME_DIR "/home/utente"
#define DIM_FILEPATH 256
#define DIM 200
#define DIM_DATA 30

static volatile sig_atomic_t numero_richieste = 0;

void handlerCtrl()
{
    printf("Numero di richieste servite: %d\n", numero_richieste);
    exit(0);
}

int main(int argc, char **argv)
{
    int status, fd, pid, p1p2[2], p2p3[2], p3p0[2], nread, n_spettacoli;
    char filepath[DIM_FILEPATH], ris[DIM], data[DIM_DATA], nome_spettacolo[DIM];

    if (argc != 2)
    {
        fprintf(stderr, "Errore argomenti: uso %s <nomeTeatro>\n", argv[0]);
        exit(1);
    }

    if (argv[1][0] == '/')
    {
        fprintf(stderr, "Errore: <nomeTeatro> deve essere una stringa\n");
        exit(2);
    }

    sprintf(filepath, "%s/%s.txt", HOME_DIR, argv[1]);
    if ((fd = open(filepath, O_RDONLY)) < 0)
    {
        fprintf(stderr, "Errore, impossibile aprire in lettura %s\n", filepath);
        exit(3);
    }
    close(fd);

    signal(SIGINT, handlerCtrl);

    while (1)
    {
        printf("Inserisci il nome dello spettacolo: ");
        scanf("%s", nome_spettacolo);

        printf("Inserisci il numero di spettacoli: ");
        scanf("%d", &n_spettacoli);

        if (n_spettacoli == 0)
        {
            break;
        }
        else if (n_spettacoli < 0)
        {
            printf("warning: <n> intero negativo\n");
            continue;
        }

        if (pipe(p1p2) < 0)
        {
            perror("P0: Errore pipe p1p2");
            exit(4);
        }

        if ((pid = fork()) < 0)
        {
            perror("Errore fork P0");
            exit(5);
        }

        if (pid == 0)
        {
            // codice P1
            signal(SIGINT, SIG_DFL);

            close(p1p2[0]);

            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("grep", "grep", nome_spettacolo, filepath, (char *)0);
            perror("Errore grep P1");
            exit(6);
        }

        if ((pipe(p2p3)) < 0)
        {
            perror("P0: errore pipe p2p3");
            exit(7);
        }

        if ((pid = fork()) < 0)
        {
            perror("Errore fork P2");
            exit(8);
        }

        if (pid == 0)
        {
            // codice P2
            signal(SIGINT, SIG_DFL);

            close(p1p2[1]);
            close(p2p3[0]);

            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            close(1);
            dup(p2p3[1]);
            close(p2p3[1]);

            execlp("sort", "sort", "-n", (char *)0);
            perror("P2: errore sort");
            exit(9);
        }

        if ((pipe(p3p0)) < 0)
        {
            perror("P0: errore pipe p3p0");
            exit(10);
        }

        if ((pid = fork()) < 0)
        {
            perror("Errore fork P3");
            exit(11);
        }

        if (pid == 0)
        {
            // codice P3
            char n_str[4];
            sprintf(n_str, "%d", n_spettacoli);

            close(p1p2[0]);
            close(p1p2[1]);
            close(p2p3[1]);
            close(p3p0[0]);

            close(0);
            dup(p2p3[0]);
            close(p2p3[0]);

            close(1);
            dup(p3p0[1]);
            close(p3p0[1]);

            execlp("head", "head", n_str, (char *)0);
            perror("P3: errore head");
            exit(12);
        }

        close(p1p2[0]);
        close(p1p2[1]);
        close(p2p3[0]);
        close(p2p3[1]);
        close(p3p0[1]);

        wait(&status);
        wait(&status);
        wait(&status);

        nread = read(p3p0[0], ris, sizeof(ris) - 1);
        if (nread < 0)
        {
            fprintf(stderr, "P0: Errore read");
            exit(13);
        }

        close(p3p0[0]);

        ris[nread] = '\0';
        printf("%s\n", ris);

        numero_richieste++;
    }

    printf("Numero di richieste servite: %d\n", numero_richieste);
    return 0;
}
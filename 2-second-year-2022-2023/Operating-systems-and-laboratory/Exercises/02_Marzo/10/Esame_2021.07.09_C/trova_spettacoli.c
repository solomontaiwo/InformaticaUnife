// interfaccia: trova_spettacoli nomeTeatro
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define DIM_FILEPATH 200
#define DIM_SPETTACOLO 200
#define DIM_RIS 2048
#define ROOT_PATH "/home/studente"

static volatile sig_atomic_t count = 0;

void handler()
{
    printf("Numero di richieste servite: %d\n", count);
    exit(0);
}

int main(int argc, char **argv)
{
    int fd, n, p1p2[2], p2p3[2], p0p3[2], pid, status, nread;
    char filepath[DIM_FILEPATH], spettacolo[DIM_SPETTACOLO], ris[DIM_RIS];

    if (argc != 2)
    {
        printf("Errore: numero sbagliato di parametri\n");
        printf("Usage: trova_spettacoli <nomeTeatro>\n");
        exit(1);
    }

    sprintf(filepath, "%s/%s.txt", ROOT_PATH, argv[1]);
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
    {
        perror("P0: open");
        exit(2);
    }
    close(fd);

    signal(SIGINT, handler);

    while (1)
    {
        printf("Inserire nome spettacolo: ");
        scanf("%s", spettacolo);

        printf("Inserire numero di spettacoli: ");
        scanf("%d", &n);

        if (n == 0)
        {
            break;
        }
        else if (n < 0)
        {
            printf("Warning: <n> intero negativo\n");
            continue;
        }

        if (pipe(p1p2) < 0)
        {
            perror("P0: pipe p1p2");
            exit(3);
        }

        pid = fork();
        if (pid < 0)
        {
            perror("P0: fork P1");
            exit(4);
        }

        if (pid == 0)
        {
            // codice P2
            signal(SIGINT, SIG_DFL);
            close(p1p2[1]);
            close(p2p3[0]);

            // redirigo stdin
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            // redirigo stdout
            close(1);
            dup(p2p3[1]);
            close(p2p3[1]);

            execlp("sort", "sort", "-n", (char *)0);
            perror("P2: sort");
            exit(8);
        }

        if (pipe(p0p3) < 0)
        {
            perror("P0: pipe p0p3");
            exit(9);
        }

        pid = fork();
        if (pid < 0)
        {
            perror("P0: fork P3");
            exit(10);
        }
        if (pid == 0)
        {
            char str_n[4];

            signal(SIGINT, SIG_DFL);

            close(p1p2[0]);
            close(p1p2[1]);
            close(p2p3[1]);
            close(p0p3[0]);

            close(0);
            dup(p2p3[0]);
            close(p2p3[0]);

            close(1);
            dup(p0p3[1]);
            close(p0p3[1]);

            sprintf(str_n, "%d", n);
            execlp("head", "head", "-n", str_n, (char *)0);
            perror("P3: head");
            exit(11);
        }

        close(p1p2[0]);
        close(p1p2[1]);

        close(p2p3[0]);
        close(p2p3[1]);

        close(p0p3[1]);

        wait(&status);
        wait(&status);
        wait(&status);

        nread = read(p0p3[0], ris, sizeof(ris) - 1);
        if (nread < 0)
        {
            perror("P0: read");
            exit(12);
        }

        close(p0p3[0]);

        ris[nread] = '\0';
        printf("%s\n", ris);

        count++;
    }

    printf("Numero richieste servite: %d\n", count);
}
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define DIM_REF 100
#define DIM_FP 200
#define DIM_RES 1024

#define ERR_MSG "nessun risultato trovato\n"

static volatile sig_atomic_t count = 0;

void handler()
{
    printf("numero di byte ricevuti: %d\n", count);
    exit(0);
}

int main(int argc, char *argv[])
{
    int fd, pid, p0p1[2], p0p2[2], status, nread, nwrite;
    char ref[DIM_REF], filepath[DIM_FP], res[DIM_RES];

    // controllo che il numero di parametri sia corretto
    if (argc != 3)
    {
        printf("errore: numero sbagliato di parametri\n");
        printf("usage: test_eseguiti <dir> <data>\n");
        exit(1);
    }

    // controllo che <dir> sia un path relativo
    if (argv[1][0] == '/')
    {
        printf("errore: <dir> deve essere path relativo\n");
        exit(2);
    }

    // controllo che <dir> sia una directory
    fd = open(argv[1], O_DIRECTORY);
    if (fd < 0)
    {
        perror("P0: open");
        exit(3);
    }
    close(fd);

    // controllo che <data> esista
    sprintf(filepath, "%s/%s.txt", argv[1], argv[2]);
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
    {
        perror("P0: open");
        exit(4);
    }
    close(fd);

    // imposto la gestione il segnale Ctrl-C
    signal(SIGINT, handler);

    // creo pipe per comunicazione tra P0 e P1
    if (pipe(p0p1) < 0)
    {
        perror("P0: pipe p0p1");
        exit(5);
    }

    // creo pipe per comunicazione tra P0 e P2
    if (pipe(p0p2) < 0)
    {
        perror("P0: pipe p0p2");
        exit(6);
    }

    pid = fork();
    if (pid < 0)
    {
        perror("P0: fork");
        exit(7);
    }
    if (pid == 0)
    {
        /*
            codice P1
        */

        // chiudo pipe tra P0 e P1 lato scrittura
        close(p0p1[1]);

        // chiudo pipe tra P0 e P2 lato lettura
        close(p0p2[0]);

        // imposto gestione SIGINT default
        signal(SIGINT, SIG_DFL);

        while (1)
        {
            // leggo refertatore inviato da P0
            nread = read(p0p1[0], ref, sizeof(ref) - 1);
            if (nread < 0)
            {
                perror("P1: read");
                exit(8);
            }
            ref[nread] = '\0';

            pid = fork();
            if (pid < 0)
            {
                perror("P1: fork");
                exit(9);
            }
            if (pid == 0)
            {
                /*
                    codice P2
                */

                // chiudo pipe tra P0 e P1 lato lettura
                close(p0p1[0]);

                // ridirigo lo stdout
                close(1);
                dup(p0p2[1]);

                // chiudo pipe tra P0 e P2 lato scrittura
                close(p0p2[1]);

                execlp("grep", "grep", ref, filepath, (char *)0);
                perror("P2: grep");
                exit(10);
            }

            // attendo terminazione P2
            wait(&status);
        }
    }

    // chiudo pipe tra P0 e P1 lato lettura
    close(p0p1[0]);

    // chiudo pipe tra P0 e P2 lato scrittura
    close(p0p2[1]);

    while (1)
    {

        printf("inserire refertatore\n");
        scanf("%s", ref);

        // P0 invia refertatore a P1
        nwrite = write(p0p1[1], ref, strlen(ref) + 1);
        if (nwrite != (int)(strlen(ref) + 1))
        {
            perror("P0: write");
            exit(11);
        }

        // P0 legge e stampa i risultati inviati da P2
        nread = read(p0p2[0], res, sizeof(res) - 1);
        if (nread < 0)
        {
            perror("P0: read");
            exit(12);
        }
        res[nread] = '\0';
        printf("%s\n", res);

        // incremento contatore byte ricevuti
        count += nread;
    }

    return 0;
}

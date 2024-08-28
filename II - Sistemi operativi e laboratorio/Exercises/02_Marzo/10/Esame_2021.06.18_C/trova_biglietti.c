// interfaccia: trova_biglietti destinazione N
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

#define DIM_FILEPATH 200
#define DIM_DATE 32
#define DIM_STR_N 20
#define ROOT_PATH "/var/local/ticket"

static volatile sig_atomic_t count = 0;

void handler()
{
    printf("Numero di richieste servite: %d\n", count);
    exit(0);
}

int main(int argc, char **argv)
{
    int fd, n, gg, mm, yyyy, p1p2[2], p2p3[2], pid, status;
    char filepath[DIM_FILEPATH], date[DIM_DATE];

    if (argc != 3)
    {
        printf("Errore: numero di parametri sbagliato\n");
        printf("Usage: trova_biglietti <destinazione> <n>\n");
        exit(1);
    }

    if ((n = atoi(argv[2])) <= 0)
    {
        printf("Errore: <n> deve essere un intero positivo\n");
        exit(2);
    }

    sprintf(filepath, "%s/%s.txt", ROOT_PATH, argv[1]);
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
    {
        perror("P0: open");
        exit(3);
    }
    close(fd);

    signal(SIGINT, handler);

    while (1)
    {
        printf("Inserire giorno, mese e anno (GG MM YYYY): ");
        scanf("%d %d %d", &gg, &mm, &yyyy);

        if (gg == -1 || mm == -1 || yyyy == -1)
        {
            break;
        }
        else if (gg < 0 || mm < 0 || yyyy < 0)
        {
            printf("Errore: inserire interi positivi\n");
            continue;
        }
        else if (gg < 1 || gg > 31)
        {
            printf("Errore: inserire <giorno> compreso tra 1 e 31\n");
            continue;
        }
        else if (mm < 1 || mm > 12)
        {
            printf("Errore: inserire <mese> compreso tra 0 e 12\n");
            continue;
        }

        sprintf(date, "%02d%02d%04d", gg, mm, yyyy);

        if (pipe(p1p2) < 0)
        {
            perror("P0: pipe p1p2");
            exit(4);
        }

        if (pipe(p2p3) < 0)
        {
            perror("P0: pipe p2p3");
            exit(5);
        }

        pid = fork();
        if (pid < 0)
        {
            perror("P0: fork P1");
            exit(6);
        }
        if (pid == 0)
        {
            // codice P1

            signal(SIGINT, SIG_DFL);

            close(p2p3[0]);
            close(p2p3[1]);

            close(p1p2[0]); // chiudo lettura perchè dovrò scrivere a P2

            // redirezione output
            close(1);
            dup(p1p2[1]);

            close(p1p2[1]);

            execlp("grep", "grep", date, filepath, (char *)0);
            perror("P1: grep");
            exit(7);
        }

        pid = fork();
        if (pid < 0)
        {
            perror("P0: fork P2");
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
            perror("P2: sort");
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
            // codice P3
            char str_n[DIM_STR_N];

            signal(SIGINT, SIG_DFL);

            close(p1p2[0]);
            close(p1p2[1]);

            close(0);
            dup(p2p3[0]);

            close(p2p3[0]);

            close(p2p3[1]);

            sprintf(str_n, "%d", n);
            execlp("head", "head", "-n", str_n, (char *)0);
            perror("P3: head");
            exit(11);
        }

        close(p1p2[0]);
        close(p1p2[1]);

        close(p2p3[0]);
        close(p2p3[1]);

        wait(&status);
        wait(&status);
        wait(&status);

        count++;
    }

    printf("Numero di richieste servite: %d\n", count);
    return 0;
}
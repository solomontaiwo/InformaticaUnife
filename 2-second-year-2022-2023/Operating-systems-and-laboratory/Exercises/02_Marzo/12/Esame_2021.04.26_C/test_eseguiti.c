// interfaccia: test_eseguiti dir data
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

#define DIM_REF 100
#define DIM_FP 200
#define DIM_RES 1024

#define ERR_MSG "Nessun risultato trovato\n"

static volatile sig_atomic_t count = 0;

void handler()
{
    printf("Numero di byte ricevuti: %d\n", count);
    exit(0);
}

int main(int argc, char **argv)
{
    int fd, pid, p0p1[2], p0p2[2], status, nread, nwrite;
    char ref[DIM_REF], filepath[DIM_FP], res[DIM_RES];

    if (argc != 3)
    {
        fprintf(stderr, "Errore: numero sbagliato di parametri\n");
        printf("Uso: %s <dir> <data>\n", argv[0]);
        exit(1);
    }

    if (argv[1][0] == '/')
    {
        printf("Errore: <dir> deve essere un path relativo\n");
        exit(2);
    }

    fd = open(argv[1], O_DIRECTORY);
    if (fd < 0)
    {
        perror("P0: open directory");
        exit(3);
    }
    close(fd);

    sprintf(filepath, "%s/%s.txt", argv[1], argv[2]);
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
    {
        perror("P0: open file");
        exit(4);
    }
    close(fd);

    signal(SIGINT, handler);

    if (pipe(p0p1) < 0)
    {
        perror("P0: pipe p0p1");
        exit(5);
    }

    pid = fork();
    if (pid < 0)
    {
        perror("P0: fork()");
        exit(6);
    }

    if (pid == 0)
    {
        close(p0p1[1]);
        close(p0p2[0]);

        signal(SIGINT, SIG_DFL);

        while (1)
        {
            nread = read(p0p1[0], ref, sizeof(ref) - 1);
            if (nread < 0)
            {
                perror("P1: read()");
                exit(7);
            }
            ref[nread] = '\0';

            pid = fork();
            if (pid < 0)
            {
                perror("P1: fork()");
                exit(8);
            }

            if (pid == 0)
            {
                close(p0p1[0]);

                close(1);
                dup(p0p2[1]);

                close(p0p2[1]);

                execlp("grep", "grep", ref, filepath, (char *)0);
                perror("P2: grep");
                exit(10);
            }

            wait(&status);
        }
    }

    close(p0p1[0]);
    close(p0p2[1]);

    while (1)
    {
        printf("Inserire refertatore\n");
        scanf("%s", ref);

        nwrite = write(p0p1[1], ref, strlen(ref) + 1);
        if (nwrite != (int)(strlen(ref) + 1))
        {
            perror("P0: write");
            exit(11);
        }

        nread = read(p0p2[0], res, sizeof(res) - 1);
        if (nread < 0)
        {
            perror("P0: read");
            exit(12);
        }
        res[nread] = '\0';
        printf("%s\n", res);

        count += nread;
    }
    return 0;
}
// interfaccio: ./ricerca_files Timeout S1 S2 ... Sn
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

#define STR_BUF_SIZE 100

int timeout;

void ctrlc_handler(int segnale)
{
    printf("Ricevuto ctrl-C; timeout (%d secondi) e terminazione...\n", timeout);
    alarm(timeout);
}

void alarm_handler(int segnale)
{
    printf("Terminazione!\n");
    kill(0, SIGKILL); // segnale mandato a tutti i processi, pid 0
}

int main(int argc, char **argv)
{
    typedef int piped[2];
    int i, status, nread, nProc;
    char buff[STR_BUF_SIZE], nomefile[STR_BUF_SIZE];
    struct sigaction sign, sigint, sigalrm;
    piped *p0pi, *pip0;

    if (argc <= 2)
    {
        fprintf(stderr, "Uso corretto: ./ricerca_files <timeout> <S1> [<S2> ... <Sn>]\n");
        exit(2);
    }
    for (i = 0; i < strlen(argv[1]); i++)
    {
        if ((argv[1][i] < '0') || (argv[1][i] > '9'))
        {
            fprintf(stderr, "Il parametro <timeout> deve essere un intero positivo\n");
            exit(3);
        }
    }
    timeout = atoi(argv[1]);

    nProc = argc - 2;
    p0pi = (piped *)malloc(nProc * sizeof(piped));
    pip0 = (piped *)malloc(nProc * sizeof(piped));

    sigemptyset(&sign.sa_mask);
    sign.sa_flags = 0;
    sign.sa_handler = SIG_IGN;

    if (sigaction(SIGINT, &sign, NULL) < 0)
    {
        perror("Padre: error in sigaction SIGINT");
        exit(-2);
    }
    if (sigaction(SIGALRM, &sign, NULL) < 0)
    {
        perror("Padre: error in sigaction SIGALARM");
        exit(-2);
    }

    for (i = 0; i < nProc; i++)
    {
        int pid;

        if (pipe(p0pi[i]) < 0)
        {
            perror("Errore pipe p0p1");
            exit(-3);
        }
        if (pipe(pip0[0]) < 0)
        {
            perror("Errore pipe pip0");
            exit(-4);
        }

        if ((pid = fork()) < 0)
        {
            perror("Errore fork()");
            exit(-5);
        }
        if (pid == 0)
        {
            int j;
            for (j = 0; j <= i; j++)
            {
                close(p0pi[j][1]);
                close(pip0[j][0]);
            }

            while (1)
            {
                if ((nread = read(p0pi[i][0], nomefile, STR_BUF_SIZE)) < 0)
                {
                    perror("read da pipe");
                    exit(5);
                }
                if ((pid = fork()) < 0)
                {
                    perror("fork()");
                    exit(6);
                }
                if (pid == 0)
                {
                    close(p0pi[i][0]);
                    close(1);
                    dup(pip0[i][1]);
                    close(pip0[i][1]);

                    execlp("grep", "grep", "-c", argv[i + 2], nomefile, (char *)0);
                    perror("execlp");
                    exit(7);
                }
                wait(&status);
            }
            exit(8);
        }
        close(p0pi[i][0]);
        close(pip0[i][1]);
    }

    sigemptyset(&sigint.sa_mask);
    sigint.sa_flags = 0;
    sigint.sa_handler = ctrlc_handler;

    if (sigaction(SIGINT, &sigint, NULL) == -1)
    {
        perror("Errore nell'intsallazione dell'handler per SIGINT");
        exit(-4);
    }

    sigemptyset(&sigalrm.sa_mask);
    sigalrm.sa_flags = 0;
    sigalrm.sa_flags = 0;
    sigalrm.sa_handler = alarm_handler;
    if (sigaction(SIGALRM, &sigalrm, NULL) == -1)
    {
        perror("Errore nell'installazione dell'handler per SIGALRM");
        exit(-5);
    }

    while (1)
    {
        int fd;
        memset(nomefile, 0, STR_BUF_SIZE);
        printf("Inserire il nome del file:\n");
        scanf("%s", nomefile);

        if (nomefile[0] == '/')
        {
            fprintf(stderr, "Il percorso inserito non è relativo.\n\n");
            continue;
        }
        else if ((fd = open(nomefile, O_RDONLY)) < 0)
        {
            fprintf(stderr, "Il percorso inserito non rappresente un nome di file valido.\n\n");
            continue;
        }
        close(fd);

        for (i = 0; i < nProc; i++)
        {
            write(p0pi[i][0], nomefile, strlen(nomefile) + 1);
        }
        for (i = 0; i < nProc; i++)
        {
            nread = read(pip0[i][0], buff, STR_BUF_SIZE);
            buff[nread - 1] = '\0';
            printf("La stringa %s compare nel file %s %s volte\n", argv[i + 2], nomefile, buff);
        }
    }
}
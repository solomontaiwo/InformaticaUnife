#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

// dichiarazione dei signal handler
void start_race(int);
void defeat(int);
void defeat_padre(int);
void timeout_handler(int);

static int termination;
static unsigned int child_index;
static unsigned long found_chars;

int main(int argc, char **argv)
{
    int fd, status;
    unsigned int i, check_index, nProc, timeout;
    ssize_t nread;
    char *file_name, target_char, read_char;

    if (argc < 4)
    {
        fprintf(stderr, "Uso corretto: %s C1 [C2 ... Cn] <NomeFile> <NumSec>\n", argv[0]);
        exit(1);
    }
    for (check_index = 1; check_index < (unsigned int)(argc - 2); check_index++)
    {
        if (strlen(argv[check_index]) != 1)
        {
            fprintf(stderr, "Ogni carametro C_i deve essere un singolo carattere\n");
            exit(2);
        }
    }

    nProc = check_index - 1;

    if ((fd = open(argv[check_index], O_RDONLY)) < 0)
    {
        fprintf(stderr, "Il file %s non esiste\n", argv[check_index]);
        exit(4);
    }
    close(fd);
    file_name = argv[check_index];

    check_index++;

    for (i = 0; i < strlen(argv[check_index]); i++)
    {
        if ((argv[check_index][i] < '0') || (argv[check_index][i] > '9'))
        {
            fprint(stderr, "Il parametro deve essere un intero positivo\n");
            exit(5);
        }
    }

    timeout = (unsigned int)atoi(argv[check_index]);
    termination = found_chars = 0;

    signal(SIGINT, start_race);
    signal(SIGUSR1, defeat);
    signal(SIGUSR2, timeout_handler);

    for (i = 0; i < nProc; i++)
    {
        int pid;
        target_char = argv[i + 1][0];
        if ((pid = fork()) < 0)
        {
            perror("Errore fork\n");
            exit(7);
        }
        if (pid == 0)
        {
            child_index = i + 1;
            if ((fd = open(file_name, O_RDONLY)) < 0)
            {
                fprintf(stderr, "Figlio %d: errore in fase di apertura file\n", child_index);
                exit(8);
            }

            pause();

            while ((nread = read(fd, &read_char, 1)) > 0)
            {
                if (target_char == read_char)
                {
                    found_chars++;
                }
            }

            signal(SIGUSR1, SIG_IGN);

            kill(0, SIGUSR1);
            printf("Figlio %d: Vittoria! Trovati %lu caratteri\n", child_index, found_chars);
            exit(0);
        }
    }

    printf("Pronti, partenza...\n");
    signal(SIGINT, SIG_IGN);
    signal(SIGUSR1, defeat_padre);
    signal(SIGUSR2, SIG_IGN);

    sleep(2);

    printf("VIA!\n\n");
    kill(0, SIGINT);

    sleep(timeout);

    if (!termination)
    {
        kill(0, SIGUSR2);
    }

    for (i = 0; i < nProc; i++)
    {
        wait(&status);
    }

    if (!termination)
    {
        printf("Padre: gara terminata regolarmente!\n");
    }
    else
    {
        printf("Padre: gara terminata in anticipo!\n");
    }

    return 0;
}

void star_race(int signal)
{
    printf("Figlio %d: inizio conteggio caratteri...\n", child_index);
}

void defeat(int signal)
{
    printf("Figlio %d: sconfitta! Trovati %lu caratteri\n", child_index, found_chars);
    exit(0);
}

void defeat_padre(int signal)
{
    termination = 1;
}

void timeout_handler(int signal)
{
    printf("Figlio %d: trovati %lu caratteri\n", child_index, found_chars);
    exit(0);
}
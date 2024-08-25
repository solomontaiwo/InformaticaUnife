#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

void start_race(int);
void defeat(int);
void defeat_padre(int);
void timeout_handler(int);

static volatile sig_atomic_t termination;
static volatile sig_atomic_t child_index;
static volatile sig_atomic_t found_chars;

int main(int argc, char **argv)
{

    int fd, status;
    unsigned int i, check_index, nProc, timeout;
    ssize_t nread;
    char *file_name, target_char, read_char;
    struct sigaction sigint, sigusr1, sigusr2, sigign;

    // Controllo argomenti
    if (argc < 4)
    {
        fprintf(stderr, "Uso corretto: ./%s C1 [C2 ... Cn] <NomeFile> <NumSec>\n", argv[0]);
        exit(1);
    }
    for (check_index = 1; check_index < (unsigned int)(argc - 2); ++check_index)
    {
        if (strlen(argv[check_index]) != 1)
        {
            fprintf(stderr, "Ogni parametro C_i deve essere un singolo carattere\n");
            exit(2);
        }
    }

    nProc = check_index - 1;

    /* Per controllare se il file esiste, provo ad aprirlo */
    if ((fd = open(argv[check_index], O_RDONLY)) < 0)
    {
        fprintf(stderr, "Il file %s non esiste\n", argv[check_index]);
        exit(4);
    }
    /* Chiudo il file, che a questo punto so esistere */
    close(fd);
    file_name = argv[check_index];

    ++check_index;
    // qui vado a controllare che NumSec sia effettivamente un intero
    for (i = 0; i < strlen(argv[check_index]); ++i)
    {
        if ((argv[check_index][i] < '0') || (argv[check_index][i] > '9'))
        {
            fprintf(stderr, "Il parametro deve essere un intero positivo\n");
            exit(5);
        }
    }

    timeout = (unsigned int)atoi(argv[check_index]);
    termination = found_chars = 0;

    /* installo i gestori dei segnali prima di creare i
     * figli (che erediteranno la maschera attuale). */
    sigemptyset(&sigint.sa_mask);
    sigint.sa_flags = 0;
    sigint.sa_handler = start_race;
    if (sigaction(SIGINT, &sigint, NULL) == -1)
    {
        perror("Errore nell'installazione del gestore di SIGINT");
        exit(-11);
    }

    sigemptyset(&sigusr1.sa_mask);
    sigusr1.sa_flags = 0;
    sigusr1.sa_handler = defeat;
    if (sigaction(SIGUSR1, &sigusr1, NULL) == -1)
    {
        perror("Errore nell'installazione del gestore di SIGUSR1");
        exit(-11);
    }

    sigemptyset(&sigusr2.sa_mask);
    sigusr2.sa_flags = 0;
    sigusr2.sa_handler = timeout_handler;
    if (sigaction(SIGUSR2, &sigusr2, NULL) == -1)
    {
        perror("Errore nell'installazione del gestore di SIGUSR2");
        exit(-11);
    }

    /* o utilizzo signal()*/
    /*
    signal(SIGINT, start_race);
    signal(SIGUSR1, defeat);
    signal(SIGUSR2, timeout_handler);
    */

    for (i = 0; i < nProc; ++i)
    {
        int pid;
        target_char = argv[i + 1][0];
        if ((pid = fork()) < 0)
        {
            perror("fork()");
            exit(7);
        }
        if (pid == 0)
        {
            struct sigaction sigintign;
            // Figlio Pi
            child_index = i + 1;
            if ((fd = open(file_name, O_RDONLY)) < 0)
            {
                fprintf(stderr, "Figlio %d: Errore in fase di apertura file\n", child_index);
                exit(8);
            }
            // Attendo segnale di sincronizzazione proveniente dal padre
            pause();
            while ((nread = read(fd, &read_char, 1)) > 0)
            {
                // confronto tra caratteri non tra stringhe
                if (target_char == read_char)
                {
                    ++found_chars;
                }
            }

            // Se Pi arriva qui, ha vinto la gara!
            sigemptyset(&sigintign.sa_mask);
            sigintign.sa_flags = 0;
            sigintign.sa_handler = SIG_IGN;
            sigaction(SIGUSR1, &sigintign, NULL);

            // invio il segnale a tutti i processi con lo stesso group id
            // http://man7.org/linux/man-pages/man2/kill.2.html
            // If pid equals 0, then sig is sent to every process in the process of the calling process
            kill(0, SIGUSR1);
            printf("Figlio %d: Vittoria! Trovati %d caratteri\n", child_index, found_chars);
            exit(0);
        }
    }

    /* PADRE: ignoro SIGINT e SIGUSR2,
     * installo il gestore per SIGUSR1
     * e poi invio SIGINT a tutti i processi */
    printf("Pronti, partenza...\n");
    sigemptyset(&sigign.sa_mask);
    sigign.sa_flags = 0;
    sigign.sa_handler = SIG_IGN;
    if (sigaction(SIGINT, &sigign, NULL) == -1)
    {
        perror("Errore sigaction()");
        exit(-11);
    }

    struct sigaction su1;
    sigemptyset(&su1.sa_mask);
    su1.sa_flags = 0;
    su1.sa_handler = defeat_padre;
    if (sigaction(SIGUSR1, &su1, NULL) == -1)
    {
        perror("Errore nell'impostazione di SIGUSR1 nel padre per defeat_padre");
        exit(-11);
    }

    if (sigaction(SIGUSR2, &sigign, NULL) == -1)
    {
        perror("Errore sigaction() per SIGUSR2");
        exit(-12);
    }

    sleep(2);
    printf("VIA!!!\n\n");
    kill(0, SIGINT);

    // Il padre aspetta lo scadere del timeout
    sleep(timeout);
    if (!termination)
    {
        // invia segnale a tutti i processi figli
        kill(0, SIGUSR2);
    }

    for (i = 0; i < nProc; ++i)
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

/* Definizione dei gestori di segnali */
void start_race(int signal)
{
    printf("Figlio %d: inizio conteggio caratteri...\n", child_index);
}

void defeat(int signal)
{
    printf("Figlio %d: sconfitta! Trovati %d caratteri\n", child_index, found_chars);
    exit(0);
}

void defeat_padre(int signal)
{
    termination = 1;
}

void timeout_handler(int signal)
{
    printf("Figlio %d: trovati %d caratteri\n", child_index, found_chars);
    exit(0);
}

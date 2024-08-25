#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

// dichiarazione dei signal handler
void start_race (int);
void defeat (int);
void defeat_padre (int);
void timeout_handler (int);

static volatile sig_atomic_t termination;
static volatile sig_atomic_t child_index;
static volatile sig_atomic_t found_chars;

int main (int argc, char **argv) {
	
    int fd, status;
    unsigned int i, check_index, nProc, timeout;
    ssize_t nread;
    char *file_name, target_char, read_char;

    // Controllo argomenti
    if (argc < 4) {
        fprintf(stderr, "Uso corretto: ./%s C1 [C2 ... Cn] <NomeFile> <NumSec>\n", argv[0]);
        exit(1);
    }
    for (check_index = 1; check_index < (unsigned int) (argc - 2); ++check_index) {
        if (strlen(argv[check_index]) != 1) {
            fprintf(stderr, "Ogni parametro C_i deve essere un singolo carattere\n");
            exit(2);
        }
    }
    
    // numero processi (dato dal numero di caratteri inseriti)
    nProc = check_index - 1;

    /* Per controllare se il file esiste, provo ad aprirlo */
    if ((fd = open(argv[check_index], O_RDONLY)) < 0) {
        fprintf(stderr, "Il file %s non esiste\n", argv[check_index]);
        exit(4);
    }
    /* Chiudo il file, che a questo punto so esistere */
    close(fd);
    file_name = argv[check_index];

    ++check_index;
    /* qui vado a controllare che NumSec sia effettivamente un intero
     */
    for (i = 0; i < strlen(argv[check_index]); i++) {
        if ((argv[check_index][i] < '0') || (argv[check_index][i] > '9')) {
            fprintf(stderr, "Il parametro deve essere un intero positivo\n");
            exit(5);
        }
    }

    timeout = (unsigned int) atoi(argv[check_index]);
    termination = found_chars = 0;

    /* installo i gestori dei segnali prima di creare i
    * figli (che erediteranno la maschera attuale). */
    signal(SIGINT, start_race);
    signal(SIGUSR1, defeat);
    signal(SIGUSR2, timeout_handler);

    for (i = 0; i < nProc; i++) {
        int pid;
        target_char = argv[i + 1][0];
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(7);
        }
        if (pid == 0) {
            // Figlio Pi
            child_index = i + 1;
            if ((fd = open(file_name, O_RDONLY)) < 0) {
                fprintf(stderr, "Figlio %d: Errore in fase di apertura file\n", child_index);
                exit(8);
            }
			
            // Attendo segnale di sincronizzazione proveniente dal padre
            pause();
            while ((nread = read(fd, &read_char, 1)) > 0) {
                // confronto tra caratteri non tra stringhe
                if (target_char == read_char) {
                    ++found_chars;
                }
            }

            // Se Pi arriva qui, ha vinto la gara!
            signal(SIGUSR1, SIG_IGN);
            // invio il segnale a tutti i processi con lo stesso group id
			// http://man7.org/linux/man-pages/man2/kill.2.html
			// If pid equals 0, then sig is sent to every process in the process of the calling process
            kill (0, SIGUSR1);
            printf("Figlio %d: Vittoria! Trovati %d caratteri\n", child_index, found_chars);
            exit(0);
		}
    }

    
    /* PADRE: ignoro SIGINT e SIGUSR2, 
	* installo il gestore per SIGUSR1 
	* e poi invio SIGINT a tutti i processi */
    printf("Pronti, partenza...\n");

    signal(SIGINT, SIG_IGN);
    signal(SIGUSR1, defeat_padre);
    signal(SIGUSR2, SIG_IGN);

    // sleep di sync
    sleep(2);

    printf("VIA!!!\n\n");
    // invio il segnale di start a tutti i processi con lo stesso
    // group id
    kill (0, SIGINT);

    // Il padre aspetta lo scadere del timeout
    sleep(timeout);

    // se programma terminata senza vincitori
    if (!termination) {
        // invia segnale a tutti i processi figli
        kill (0, SIGUSR2);
    }

    for (i = 0; i < nProc; ++i) {
        wait(&status);
    }
    if (!termination) {
        printf("Padre: gara terminata regolarmente!\n");
    }
    else {
        printf("Padre: gara terminata in anticipo!\n");
    }

    return 0;
}


/* Definizione dei gestori di segnali */
void start_race (int signal) {
    printf("Figlio %d: inizio conteggio caratteri...\n", child_index);
}


void defeat (int signal) {
    printf("Figlio %d: sconfitta! Trovati %d caratteri\n", child_index, found_chars);
    exit(0);
}


void defeat_padre (int signal) {
    termination = 1;
}


void timeout_handler (int signal) {
    printf("Figlio %d: trovati %d caratteri\n", child_index, found_chars);
    exit(0);
}

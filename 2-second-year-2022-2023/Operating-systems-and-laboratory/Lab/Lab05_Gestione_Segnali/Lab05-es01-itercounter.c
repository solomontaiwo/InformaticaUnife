#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_PROC_NUM 20

/* Variabili globali. */
static volatile sig_atomic_t contatore = 0;

void gestore(int signo) {
    printf("Il processo %d ha eseguito %d iterazioni per il segnale %d\n", getpid(), contatore, signo);
    exit(0);
}

int main(int argc, char** argv) {
	
    int *pid;
    int Nf, Nsec, i, status;
	
    /* Controllo argomenti */
    if (argc != 3) {
        fprintf(stderr, "Uso: ./itercounter <num_processi> <num_secondi>\n");
        exit(1);
    }
	
    Nf = atoi(argv[1]);
    if (Nf <= 0) {
        fprintf(stderr, "Il parametro <num_processi> deve essere un intero positivo\n");
        exit(2);
    } else if (Nf > MAX_PROC_NUM) {
        fprintf(stderr, "Il parametro <num_processi> non può essere maggiore di %d\n", MAX_PROC_NUM);
        exit(3);
    }
	
    Nsec = atoi(argv[2]);
    if (Nsec <= 0) {
        fprintf(stderr, "Il parametro <num_secondi> deve essere un intero positivo\n");
        exit(4);
    }

    /* Uso un array allocato dinamicamente per poter inviare SIGUSR1, attraverso la 
     * system call kill() a ogni singolo processo figlio. Alternativamente, inviando 
     * la kill() a tutto il gruppo di processi (invocando kill(0)), non ne avrei 
     * bisogno. */

    pid = (int *) malloc(Nf * sizeof(int));

    /* Genero i figli. */
    for (i = 0; i < Nf; ++i) {
        pid[i] = fork();
        if (pid[i] < 0) {
            perror("Errore nella fork\n");
            exit(5);
        }
        if (pid[i] == 0) {
            /* Codice del processo figlio*/
            
			/*imposto la gestione di SIGUSR1 con sigaction*/
            struct sigaction sa;
            sigemptyset(&sa.sa_mask);
            sa.sa_flags = 0;
            sa.sa_handler = gestore;
            if (sigaction(SIGUSR1, &sa, NULL) < 0) {
                perror("Errore in sigaction, SIGUSR1 figlio");
                exit(-3);
            }
            
            while (1) {
                sleep(1);
                contatore++;
            }
        }
    }

    /* Sono nel codice del processo padre */
    sleep(Nsec);

    // Invio SIGUSR1 a tutti i processi figli
    for(i = 0; i < Nf; ++i) {
        kill(pid[i], SIGUSR1);
    }

    /* Un'alternativa più efficiente consiste nell'inviare una sola kill(0, SIGUSR1)
     * al gruppo di processi, AVENDO CURA DI FAR IGNORARE AL PADRE IL SEGNALE IN 
     * QUESTIONE. */

    free(pid);

    /* Attendo la morte di tutti i figli (alternativamente posso installare il 
    * gestore per SIGCHLD) */
    for (i = 0; i < Nf; i++) {
        wait(&status);
    }

    // Esco senza errori
    return 0;
}

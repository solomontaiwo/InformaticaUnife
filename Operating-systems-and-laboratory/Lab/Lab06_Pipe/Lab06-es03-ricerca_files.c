#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

#define STR_BUF_SIZE 100

static volatile sig_atomic_t timeout;

void ctrlc_handler (int segnale) {
    printf("Ricevuto ctrl-C; timeout (%d secondi) e terminazione...\n", timeout);
    alarm(timeout);
}

void alarm_handler (int segnale) {
    printf("Terminazione!\n");
    kill(0, SIGKILL);
}


int main (int argc, char **argv) {
	
    typedef int piped[2];
    int i, status, nread, nProc;
    char buff[STR_BUF_SIZE], nomefile[STR_BUF_SIZE];
    struct sigaction sign, sigint, sigalrm;
    piped *p0pi, *pip0;

    // Controllo argomenti
    if (argc <= 2) {
        fprintf(stderr, "Uso corretto: ./ricercaFiles <timeout> <S1> [<S2> ... <Sn>]\n");
        exit(2);
    }
    for (i = 0; i < strlen(argv[1]); ++i) {
        if ((argv[1][i] < '0') || (argv[1][i] > '9')) {
            fprintf(stderr, "Il parametro <timeout> deve essere un intero positivo\n");
            exit(3);
        }
    }
    timeout = atoi(argv[1]);

    // Alloco dinamicamente la memoria necessaria per le pipe
    nProc = argc - 2;
    p0pi = (piped*) malloc(nProc * sizeof(piped));
    pip0 = (piped*) malloc(nProc * sizeof(piped));

    /* Ignoro i segnali prima di creare i figli (che erediteranno
    * la maschera attuale) e poi genero N processi e 2*N pipe. */
    sigemptyset(&sign.sa_mask);
    sign.sa_flags = 0;
    sign.sa_handler = SIG_IGN;

    if (sigaction(SIGINT, &sign, NULL) < 0) {
        perror("Padre: Error in sigaction SIGINT");
        exit(-2);
    }
    if (sigaction(SIGALRM, &sign, NULL) < 0) {
        perror("Padre: Error in sigaction SIGALARM");
        exit(-2);
    }

    for (i = 0; i < nProc; ++i) {
        int pid;

        // Apertura pipe da e verso il figlio i-esimo
        if (pipe(p0pi[i]) < 0) {
            perror("Errore pipe p0pi");
            exit(-3);
        }
        if (pipe(pip0[i]) < 0) {
            perror("Errore pipe pip0");
            exit(-4);
        }

        if ((pid = fork()) < 0) {
            perror("Errore fork()");
            exit(-5);
        }
        if (pid == 0) {
            // Figlio Pi
            int j;
            for(j = 0; j <= i; ++j) {
                /* Chiudo tutti gli estremi delle pipe che P0 ha
                * aperto per comunicare con i figli precedenti e
                * con quello attuale (per il quale si ha j==i)*/
                close(p0pi[j][1]);
                close(pip0[j][0]);
            }

            while (1) {
                // Continuo a iterare finché non arriva SIGKILL dal padre
                if ((nread = read(p0pi[i][0], nomefile, STR_BUF_SIZE)) < 0) {
                    perror("read da pipe");
                    exit(5);
                }
                if ((pid = fork()) < 0) {
                    perror("fork()");
                    exit(6);
                }
                if (pid == 0) {
                    // Redirezione e chiusura pipe
                    close(p0pi[i][0]);
                    close(1);
                    dup(pip0[i][1]);
                    close(pip0[i][1]);

                    execlp("grep", "grep", "-c", argv[i + 2], nomefile, (char *) 0);
                    perror("execlp");
                    exit(7);
                }
                wait(&status);
            }

            // Pi non dovrebbe mai raggiungere questo punto
            exit(8);
        }

        // PADRE: Chiudo le pipe che non mi servono
        close(p0pi[i][0]);
        close(pip0[i][1]);
    }


    // PADRE: Installo i gestori dei segnali nel padre
    sigemptyset(&sigint.sa_mask);
    sigint.sa_flags = 0;
    sigint.sa_handler = ctrlc_handler;

    if(sigaction(SIGINT, &sigint, NULL) == -1){
        perror("Errore nell'installazione dell'handler per SIGINT");
        exit(-4);
    }

    sigemptyset(&sigalrm.sa_mask);
    sigalrm.sa_flags = 0;
    sigalrm.sa_handler = alarm_handler;
	
    if(sigaction(SIGALRM, &sigalrm, NULL) == -1){
        perror("Errore nell'installazione dell'handler per SIGALRM");
        exit(-5);
    }

    while(1) {
        int fd;
        memset(nomefile, 0, STR_BUF_SIZE);
        printf("Inserire il nome del file:\n");
        scanf("%s", nomefile);

        if (nomefile[0] == '/') {
            fprintf(stderr, "Il percorso inserito non è relativo.\n\n");
            continue;
        }
        else if ((fd = open(nomefile, O_RDONLY)) < 0) {
            fprintf(stderr, "Il percorso inserito non rappresenta un nome di file valido.\n\n");
            continue;
        }
        close(fd);

        for (i = 0; i < nProc; ++i) {
            // Invio anche il carattere di fine stringa
            write(p0pi[i][1], nomefile, strlen(nomefile) + 1);
        }
        for (i = 0; i < nProc; ++i) {
            nread = read(pip0[i][0], buff, STR_BUF_SIZE);
            buff[nread - 1] = '\0';
            printf("La stringa %s compare nel file %s %s volte\n", argv[i+2], nomefile, buff);
        }
    }
}

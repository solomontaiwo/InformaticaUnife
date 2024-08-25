#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define DIM 80


static volatile sig_atomic_t contatore_richieste = 0;

/*
 * Gestore per il segnale di Ctrl-C
 *
 */
void gestore(int signo) {
    printf("Sono state eseguite %d ricerche, termino\n", contatore_richieste);
    exit(0);
}


int main(int argc, char** argv) {

    int fd, p1, p2, p1p2[2], status;
    char cognome[DIM];
    char prefisso[DIM];

    // Controllo argomenti
    if (argc != 2) {
        fprintf(stderr, "%s <file_anagrafica>\n", argv[0]);
        exit(-1);
    }

    // file_anagrafica deve avere path assoluta
    if (argv[1][0] != '/') {
        fprintf(stderr, "%s deve avere path assoluta\n", argv[1]);
        exit(-2);
    }

    // controllo esistenza file
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Errore nell'apertura del file %s\n", argv[1]);
        exit(-2);
    }
    close(fd);

    // Imposto la gestione per il segnale di Ctrl-C
    signal(SIGINT, gestore);

    while (1) {

        printf("Inserisci il cognome da ricercare\n");
        scanf("%s", cognome);
        if (!strcmp(cognome, "fine") ) break;

        printf("Inserirsci il prefisso di interesse\n");
        scanf("%s", prefisso);
        if (!strcmp(cognome, "fine")) break;

        // P0 deve creare due figli
        // Creo la pipe per la comunicazione p1 p2

        if (pipe(p1p2) < 0) {
            perror("Errore pipe() p1p2");
            exit(-3);
        }

        p1 = fork();
        if (p1 < 0) {
            perror("Errore fork() p1");
            exit(-4);
        }

        // Codice del processo p1
        if (p1 == 0) {
            close(p1p2[0]);
            // redirect stdout
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);
            // grep cognome file_anagrafica
            execlp("grep", "grep", cognome, argv[1], (char *)0);
            perror("Errore grep p1");
            exit(-5);
        }

        // creo processo P2

        p2 = fork();
        if (p2 < 0) {
            perror("Errore fork() p2");
            exit(-6);
        }
        // codice del processo p2
        if (p2 == 0) {
            close(p1p2[1]);

            // redirect stdin
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            // grep prefisso
            execlp("grep", "grep", prefisso, (char *)0);
            perror("Errore grep prefisso");
            exit(-6);
        }

        close(p1p2[0]);
        close(p1p2[1]);
        wait(&status);
        wait(&status);
        // incremento il contatore delle richieste
        contatore_richieste++;
    }

    // Stampo numero delle richieste servite
    printf("Servite %d richieste, termino\n", contatore_richieste);

    return 0;
}

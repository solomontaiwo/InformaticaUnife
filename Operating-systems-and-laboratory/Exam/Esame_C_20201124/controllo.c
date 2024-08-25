#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define DIM 80
#define BUFDIM 256

/* 
 * Byte letti dal processo P2
*/

static volatile sig_atomic_t byte_p2 = 0;


/*
 * Gestore per il segnale di Ctrl-C
 *
 */
void gestore(int signo) {
    printf("Byte letti dal processo P2: %d\n", byte_p2);
    exit(0);
}


int main(int argc, char** argv) {

    int fd, p1, p2, p1p2[2], p2p0[2], status;
    char cognome[DIM];
    char libro[DIM];
    char buff[BUFDIM];

    // Controllo argomenti
    if (argc != 2) {
        fprintf(stderr, "%s <dir> \n", argv[0]);
        exit(-1);
    }

    // dir deve avere path assoluta
    if (argv[1][0] != '/') {
        fprintf(stderr, "%s deve avere path assoluta\n", argv[1]);
        exit(-2);
    }

    // controllo esistenza della directory
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Errore nell'apertura della directory %s\n", argv[1]);
        exit(-2);
    }
    close(fd);

    // Imposto la gestione per il segnale di Ctrl-C
    signal(SIGINT, gestore);


    printf("Inserisci il cognome da ricercare\n");
    scanf("%s", cognome);

    printf("Inserirsci il libro di interesse\n");
    scanf("%s", libro);

    // se non ho inserito fine 
    while ((strcmp(cognome, "fine") !=0) && (strcmp(libro, "fine") != 0)) {

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

        // Codice del processo P1
        // deve Cercare la sottodirectory e il 
        // file corrispondente al libro di interesse
        if (p1 == 0) {
            char path_libro[128];
            // path_libro contiene le informazioni sui prestiti all'utente cognome
            // per il libro di interesse 
            sprintf(path_libro, "%s/%s/%s", argv[1], libro, cognome);
            printf("File da ricercare %s\n", path_libro);
            fd = open(path_libro, O_RDONLY);

            if (fd < 0) {
                perror("Non esiste un file corrispondente");
                continue;
            }
            close(fd);

            // pipe comandi
            close(p1p2[0]);
            // redirect stdout
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);
            // sort anno
            execlp("sort", "sort", path_libro, (char *)0);
            perror("Errore sort p1");
            exit(-5);
        }

        // creo la pipe per comunicazione
        // P2 -> P0
        if (pipe(p2p0) < 0) {
            perror("Errore creazione pipe p2p0");
            exit(-6);
        }

        // creo processo P2
        p2 = fork();
        if (p2 < 0) {
            perror("Errore fork() p2");
            exit(-7);
        }
        // codice del processo p2
        // deve seleziona solo i prestiti già restituiti
        // e inviarli al processo P0
        if (p2 == 0) {
            close(p1p2[1]);

            // redirect stdin
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            //redirct stdout
            close(p2p0[0]);
            close(1);
            dup(p2p0[1]);
            close(p2p0[1]);

            // grep ingresso
            execlp("grep", "grep", "ingresso", (char *)0);
            perror("Errore grep p2");
            exit(-6);
        }

        // terminazione processo p1
        close(p1p2[0]);
        close(p1p2[1]);
        wait(&status);

        // canale non neccessario P2 -> P0
        close(p2p0[1]);
        
        // leggo le informazioni
        int byte_ricerca = 0;

        memset(buff, 0, BUFDIM);
        while((byte_ricerca = read(p2p0[0], buff, sizeof(buff))) > 0) {
            write(1, buff, byte_ricerca);
            byte_p2 += byte_ricerca;
            memset(buff, 0, BUFDIM);
        }

        close(p2p0[0]);
        wait(&status);

        // chiedo cognome e libro da ricercare

        printf("Inserisci il cognome da ricercare\n");
        scanf("%s", cognome);

        printf("Inserirsci il libro di interesse\n");
        scanf("%s", libro);
    }

    printf("Numero totale di byte letti da P2 %d\n", byte_p2);

    return 0;
}

#define _POSIX_C_SOURCE 200809L
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define DIM 4096

int main(int argc, char** argv) {
        int err;
        struct addrinfo hints;
        struct addrinfo *res,*ptr;
        char *host_remoto;
        char *servizio_remoto;
        char *stringa;
        char *nome_file;
        int sd, nread;
        char buf[DIM], ack[10];
        int i=1;
        char *ackVer="ack\n";

        /* Controllo argomenti */
        if (argc < 5){
                printf("Uso: rgrep <server> <porta> <stringa> <nomeFile>...\n");
                exit(EXIT_FAILURE);
        }

	/* Ignoro SIGPIPE */
	signal(SIGPIPE, SIG_IGN);

        /* Costruzione dell'indirizzo */
        memset(&hints, 0, sizeof(hints));
        hints.ai_family   = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;

        /* Risoluzione dell'host */
        host_remoto = argv[1];
        servizio_remoto = argv[2];
        stringa = argv[3];
        nome_file = argv[4];

        if ((err = getaddrinfo(host_remoto, servizio_remoto, &hints, &res)) != 0) {
                fprintf(stderr, "Errore risoluzione nome: %s\n", gai_strerror(err));
                exit(EXIT_FAILURE);
        }

        for (ptr = res; ptr != NULL; ptr = ptr->ai_next){
                /*se socket fallisce salto direttamente alla prossima iterazione*/
                if ((sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol)) < 0){
                        fprintf(stderr,"creazione socket fallita\n");
                        continue;
                }
                /*se connect funziona esco dal ciclo*/
                if (connect(sd, ptr->ai_addr, ptr->ai_addrlen) == 0){
                        printf("connect riuscita al tentativo %d\n",i);
                        break;
                }
                i++;
                close(sd);
        }

        /* Verifica sul risultato restituito da getaddrinfo */
        if (ptr == NULL) {
                fprintf(stderr, "Errore risoluzione nome: nessun indirizzo corrispondente trovato\n");
                exit(EXIT_FAILURE);
        }

        /* Liberiamo la memoria allocata da getaddrinfo() */
        freeaddrinfo(res);

        /* Scambio dati */

        /* mando il nomeFile */
        if (write(sd, nome_file, strlen(nome_file)) < 0) {
                perror("write nome_file");
                exit(EXIT_FAILURE);
        }

        /* Inizializzo il buffer a zero e leggo sizeof(ack)-1
         * byte, così sono sicuro che il contenuto del buffer
         * sarà sempre null-terminated. In questo modo, posso
         * interpretarlo come una stringa C e passarlo
         * successivamente alla funzione strcmp. */
        memset(ack, 0, sizeof(ack));
        if ((nread = read(sd, ack, sizeof(ack)-1))<0){
                perror("lettura ack");
                exit(EXIT_FAILURE);
        }

        if (strcmp(ackVer, ack) != 0){
                perror("strcmp ack");
                exit(EXIT_FAILURE);
        }

        /* mando la stringa */
        if (write(sd, stringa, strlen(stringa)) < 0){
                perror("scrittura stringa");
                exit(EXIT_FAILURE);
        }

        /* Facciamo il shutdown della scrittura sulla socket */
        shutdown(sd, SHUT_WR);

        /* Ricezione risultato */

        /* È consigliabile effettuare il flushing del buffer di printf
         * prima di iniziare a scrivere sullo standard output con write */
        fflush(stdout);

        while ((nread = read(sd, buf, DIM)) > 0) {
                if (write(1, buf, nread) < 0) {
                        perror("write su stdout");
                        exit(EXIT_FAILURE);
                }
        }

        /* Controllo errori di lettura */
        if (nread < 0) {
                perror("read dei risultati");
                exit(EXIT_FAILURE);
        }

        /* chiudo la socket */
        close(sd);

        return 0;
}

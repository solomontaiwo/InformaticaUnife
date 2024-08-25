#define _POSIX_C_SOURCE	200809L
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define DIM 4096

int main(int argc, char** argv){
        int err;
        struct addrinfo hints, *res, *ptr;
        char *host_remoto;
        char *servizio_remoto;
        int sd, nread;
        char buf[DIM];
        int i = 1;

        /* Controllo argomenti */
        if (argc < 2) {
                printf("Uso: rps <server> <options>...\n");
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
        servizio_remoto = "50000";
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

        /* Invio argomento opzionale comando ps */
        if (argc >= 3) {
                if (write(sd, argv[2], strlen(argv[2])) < 0) {
                        perror("write params");
                        exit(EXIT_FAILURE);
                }
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

        /* chiudo socket */
        close(sd);

        return 0;
}

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define DIM 4096

int main(int argc, char** argv) {
        int err;
        struct addrinfo hints;
        struct addrinfo *res,*ptr;
        char *host_remoto;
        char *servizio_remoto;
        int sd, nread;
        char buf[DIM], nome[DIM], annata[DIM];
        int i=1;
        char *ackVer="ack\n";

        /* Controllo argomenti */
        if (argc < 3) {
                printf("Uso: verifica_disponibilità_vini <server> <porta>\n");
                exit(EXIT_FAILURE);
        }

        /* Costruzione dell'indirizzo */
        memset(&hints, 0, sizeof(hints));
        hints.ai_family   = AF_INET;
        hints.ai_socktype = SOCK_STREAM;

        /* Risoluzione dell'host */
        host_remoto = argv[1];
        servizio_remoto = argv[2];

        if ((err = getaddrinfo(host_remoto, servizio_remoto, &hints, &res)) != 0) {
                fprintf(stderr, "Errore risoluzione nome: %s\n", gai_strerror(err));
                exit(EXIT_FAILURE);
        }

        for (;;) {
                /* Lettura dati dall'utente */
                printf("Inserisci il nome di un vino cui sei interessato ('fine' per uscire):\n");
                if(scanf("%s", nome) == EOF){ //ho il terminatore
                        perror("scanf");
                        exit(EXIT_FAILURE);
                } 

                if (strcmp(nome, "fine") == 0) {
                        printf("Hai scelto di terminare il programma.\n");
                        break;
                }

                /* Lettura dati dall'utente */
                printf("Inserisci l'annata di un vino cui sei interessato ('fine' per uscire):\n");
                if(scanf("%s", annata) == EOF){ //ho il terminatore
                        perror("scanf");
                        exit(EXIT_FAILURE);
                }

                if (strcmp(annata, "fine") == 0) {
                        printf("Hai scelto di terminare il programma.\n");
                        break;
                }

                /* Connessione con fallback */
                for (ptr = res; ptr != NULL; ptr = ptr->ai_next) {
                        /*se socket fallisce salto direttamente alla prossima iterazione*/
                        if ((sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol)) < 0) {
                                fprintf(stderr,"creazione socket fallita\n");
                                continue;
                        }
                        /*se connect funziona esco dal ciclo*/
                        if (connect(sd, ptr->ai_addr, ptr->ai_addrlen) == 0) {
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

                /* Mando il nome del vino al server */
                if (write(sd, nome, strlen(nome)) < 0) {
                        perror("write nome");
                        exit(EXIT_FAILURE);
                }

                /* Leggo l'ack */
                memset(buf, 0, sizeof(buf));
                if (read(sd, buf, sizeof(buf)-1) < 0) {
                        perror("read ack");
                        exit(EXIT_FAILURE);
                }

                if (strcmp(buf, ackVer) != 0) {
                        close(sd);
                        printf("errore nell'ack\n");
                        exit(EXIT_FAILURE);
                }

                /* Mando l'annata del vino al server */
                if (write(sd, annata, strlen(annata)) < 0) {
                        perror("write annata");
                        exit(EXIT_FAILURE);
                }

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
                        perror("read del risultato");
                        exit(EXIT_FAILURE);
                }

                /* Chiudo la socket */
                close(sd);
        }

        /* Liberiamo la memoria allocata da getaddrinfo() */
        freeaddrinfo(res);

        return 0;
}

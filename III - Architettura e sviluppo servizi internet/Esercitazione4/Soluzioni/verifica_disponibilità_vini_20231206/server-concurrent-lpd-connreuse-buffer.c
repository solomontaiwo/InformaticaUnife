#define _POSIX_C_SOURCE 200809L
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifdef USE_LIBUNISTRING
#  include <unistr.h> /* per libunistring */
#endif
#include "utils.h"


/* Massima lunghezza stringhe: 64 KiB */
#define MAX_REQUEST_SIZE (64 * 1024)

/* Gestore del segnale SIGCHLD */
void handler(int signo)
{
        int status;

        (void)signo; /* per evitare warning */

        /* eseguo wait non bloccanti finché ho dei figli terminati */
        while (waitpid(-1, &status, WNOHANG) > 0)
                continue;
}


int main(int argc, char **argv)
{
        int sd, err, on;
        struct addrinfo hints, *res;
        struct sigaction sa;

        /* Controllo argomenti */
        if (argc < 2) {
                printf("Uso: ./server-concurrent-lpd-connreuse-buffer <porta> \n");
                exit(EXIT_FAILURE);
        }

	/* Ignoro SIGPIPE */
	signal(SIGPIPE, SIG_IGN);

	/* Installo gestore SIGCHLD usando la syscall sigaction, che è uno
	 * standard POSIX, al posto di signal che ha semantiche diverse a
	 * seconda del sistema operativo */
        sigemptyset(&sa.sa_mask);
        /* uso SA_RESTART per evitare di dover controllare esplicitamente se
         * accept è stata interrotta da un segnale e in tal caso rilanciarla
         * (si veda il paragrafo 21.5 del testo M. Kerrisk, "The Linux
         * Programming Interface") */
        sa.sa_flags   = SA_RESTART;
        sa.sa_handler = handler;

        if (sigaction(SIGCHLD, &sa, NULL) == -1) {
                perror("sigaction");
                exit(EXIT_FAILURE);
        }

        memset(&hints, 0, sizeof(hints));
        /* Usa AF_INET per forzare solo IPv4, AF_INET6 per forzare solo IPv6 */
        hints.ai_family   = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags    = AI_PASSIVE;

        if ((err = getaddrinfo(NULL, argv[1], &hints, &res)) != 0) {
                fprintf(stderr, "Errore setup indirizzo bind: %s\n", gai_strerror(err));
                exit(EXIT_FAILURE);
        }

        if ((sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0){
                perror("Errore in socket");
                exit(EXIT_FAILURE);
        }

        on = 1;
        if(setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0){
                perror("setsockopt");
                exit(EXIT_FAILURE);
        }

        if (bind(sd, res->ai_addr, res->ai_addrlen) < 0) {
                perror("Errore in bind");
                exit(EXIT_FAILURE);
        }

        /* rilascio memoria allocata da getaddrinfo */
        freeaddrinfo(res);

        /* trasforma in socket passiva d'ascolto */
        if (listen(sd, SOMAXCONN) < 0) {
                perror("listen");
                exit(EXIT_FAILURE);
        }

        for(;;) {
                int ns, pid;

                /* Mi metto in attesa di richieste di connessione */
                if ((ns = accept(sd, NULL, NULL)) < 0) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                }

                /* Creo un processo figlio per gestire la richiesta */
                if ((pid = fork()) < 0) {
                        perror("fork");
                        exit(EXIT_FAILURE);
                } else if (pid == 0) { 
                        /* FIGLIO */

                        /* Chiudo la socket passiva */
                        close(sd);


                        for (;;) {
				uint8_t len[2], response[65536];
				char nome[MAX_REQUEST_SIZE], annata[MAX_REQUEST_SIZE];
				size_t nome_len, annata_len;
				int pipe_n2f[2], pid_n1, pid_n2, nread, read_so_far, response_len, pipe_n1n2[2];

				/* Leggo lunghezza username */
				if (read_all(ns, len, 2) < 0) {
					perror("read");
					exit(EXIT_FAILURE);
				}

				/* Decodifico lunghezza nome come intero unsigned a
				 * 16 bit in formato big endian (AKA network byte
				 * order) */
				nome_len = (size_t)len[1] | ((size_t)len[0] << 8);

				/* Inizializzo il buffer nome a zero e so che
				 * nome_len < sizeof(nome), quindi sono sicuro
				 * che il buffer sarà sempre null-terminated. In questo
				 * modo, posso interpretarlo come una stringa C e
				 * passarlo direttamente alla funzione strcmp. */
				memset(nome, 0, sizeof(nome));
				if (read_all(ns, nome, nome_len) < 0) {
					perror("read");
					exit(EXIT_FAILURE);
				}

#ifdef USE_LIBUNISTRING
				/* Verifico che il messaggio sia UTF-8 valido */
				if (u8_check((uint8_t *)nome, nome_len) != NULL) {
					/* Client che malfunziona - inviato messaggio
					 * con stringa UTF-8 non valida */
					fprintf(stderr, "Request is not valid UTF-8!\n");
					close(ns);
					exit(EXIT_SUCCESS);
				}
#endif

				/* Leggo lunghezza annata */
				if (read_all(ns, len, 2) < 0) {
					perror("read");
					exit(EXIT_FAILURE);
				}

				/* Decodifico lunghezza annata come intero unsigned a
				 * 16 bit in formato big endian (AKA network byte
				 * order) */
				annata_len = (size_t)len[1] | ((size_t)len[0] << 8);

				/* Inizializzo il buffer annata a zero e so che
				 * annata_len < sizeof(annata), quindi sono sicuro
				 * che il buffer sarà sempre null-terminated. In questo
				 * modo, posso interpretarlo come una stringa C e
				 * passarlo direttamente alla funzione strcmp. */
				memset(annata, 0, sizeof(annata));
				if (read_all(ns, annata, annata_len) < 0) {
					perror("read");
					exit(EXIT_FAILURE);
				}

#ifdef USE_LIBUNISTRING
				/* Verifico che il messaggio sia UTF-8 valido */
				if (u8_check((uint8_t *)annata, annata_len) != NULL) {
					/* Client che malfunziona - inviato messaggio
					 * con stringa UTF-8 non valida */
					fprintf(stderr, "Request is not valid UTF-8!\n");
					close(ns);
					exit(EXIT_SUCCESS);
				}
#endif
                                if (pipe(pipe_n1n2) < 0) {
                                        perror("pipe");
                                        exit(EXIT_FAILURE);
                                }

                                pid_n1 = fork();
                                if (pid_n1 < 0) {
                                        perror("fork");
                                        exit(EXIT_FAILURE);
                                } else if (pid_n1 == 0) {
                                        /* NIPOTE N1*/

                                        /* Chiudo file descriptor non usati */
                                        close(ns);
                                        close(pipe_n1n2[0]);

                                        /* Redirezione output su pipe */
                                        close(1);
                                        if (dup(pipe_n1n2[1]) < 0) {
                                                perror("dup");
                                                exit(EXIT_FAILURE);
                                        }
                                        close(pipe_n1n2[1]);

					/* Eseguo la grep sul server con i parametri corretti */
					execlp("grep", "grep", nome, "test.txt", (char*)NULL);
					perror("execlp grep 1");
					exit(EXIT_FAILURE);
                                }

                                if (pipe(pipe_n2f) < 0) {
                                        perror("pipe");
                                        exit(EXIT_FAILURE);
                                }

                                pid_n2 = fork();
                                if (pid_n2 < 0) {
                                        perror("fork");
                                        exit(EXIT_FAILURE);
                                } else if (pid_n2 == 0) {
                                        /* NIPOTE N2*/

                                        /* Chiudo file descriptor non usati */
                                        close(ns);
                                        close(pipe_n2f[0]);
                                        close(pipe_n1n2[1]);

                                        /* Redirezione input da pipe */
                                        close(0);
                                        if (dup(pipe_n1n2[0]) < 0) {
                                                perror("dup");
                                                exit(EXIT_FAILURE);
                                        }
                                        close(pipe_n2f[0]);

                                        /* Redirezione output su pipe */
                                        close(1);
                                        if (dup(pipe_n2f[1]) < 0) {
                                                perror("dup");
                                                exit(EXIT_FAILURE);
                                        }
                                        close(pipe_n2f[1]);

					/* Eseguo la grep sul server con i parametri corretti */
					execlp("grep", "grep", annata, (char*)NULL);
					perror("execlp grep 2");
					exit(EXIT_FAILURE);
                                }

                                /* FIGLIO */

                                /* Chiudo file descriptor non usati */
                                close(pipe_n2f[1]);
                                close(pipe_n1n2[0]);
                                close(pipe_n1n2[1]);
				/* Questa implementazione fa uso di un buffer
				 * di memoria in cui salvare temporaneamente la
				 * risposta. Si tratta di un'operazione
				 * necessaria perché i protocolli applicativi
				 * di tipo length-prefixed data richiedono che
				 * le risposte siano precedute da due byte che
				 * ne indicano la dimensione. Quindi dobbiamo
				 * salvarne il contenuto da qualche parte e
				 * processarlo prima di reinviarlo al Client.
				 * Un buffer di memoria è un'opzione molto
				 * semplice da realizzare, che però è
				 * applicabile solo nel caso in cui la risposta
				 * ha una dimensione massima nota a priori. Una
				 * possibile implementazione alternativa, che
				 * non soffre di questo limite ma è decisamente
				 * più complessa, è quella basata sull'uso di
				 * file temporanei. */
                                read_so_far = 0;
                                while ((nread = read(pipe_n2f[0], response + read_so_far, 
                                                     sizeof(response) - read_so_far)) > 0) {
                                        read_so_far += nread;
                                }

                                if (nread < 0) {
                                        perror("read");
                                        exit(EXIT_FAILURE);
                                }

                                if (read_so_far > 65535) {
                                        fprintf(stderr, "Troppi dati\n");
                                        exit(EXIT_FAILURE);
                                }

                                response_len = read_so_far;

                                len[0] = (uint8_t)((response_len & 0xFF00) >> 8);
                                len[1] = (uint8_t)(response_len & 0x00FF);

                                if (write_all(ns, len, 2) < 0) {
                                        perror("write");
                                        exit(EXIT_FAILURE);
                                }

                                if (write_all(ns, response, response_len) < 0) {
                                        perror("write");
                                        exit(EXIT_FAILURE);
                                }
                        }
                } 

                /* PADRE */ 

                /* Chiudo la socket attiva */
                close(ns);
        }

        close(sd);

        return 0;
}


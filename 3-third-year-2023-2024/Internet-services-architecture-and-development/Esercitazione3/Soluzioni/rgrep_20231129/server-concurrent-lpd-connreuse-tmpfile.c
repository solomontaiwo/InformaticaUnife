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
#include <limits.h>
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
                printf("Uso: ./server-concurrent-lpd-connreuse-tmpfile <porta> \n");
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

                        /* Disabilito gestore SIGCHLD */
                        signal(SIGCHLD, SIG_DFL);


                        for (;;) {
				uint8_t len[2];
				char nomefile[MAX_REQUEST_SIZE], stringa[MAX_REQUEST_SIZE], template[256];
				size_t nomefile_len, stringa_len;
				int fd, status, file, pid_n;

				/* Questa implementazione fa uso di un file in
				 * cui salvare temporaneamente la risposta. Si
				 * tratta di un'operazione necessaria perché i
				 * protocolli applicativi di tipo
				 * length-prefixed data richiedono che le
				 * risposte siano precedute da due byte che ne
				 * indicano la dimensione. Quindi dobbiamo
				 * salvarne il contenuto da qualche parte e
				 * processarlo prima di reinviarlo al Client.
				 * Una possibile implementazione alternativa
				 * sarebbe utilizzare un buffer di memoria per
				 * il salvataggio temporaneo della risposta: si
				 * tratta di una soluzione significativamente
				 * più semplice ma che però è applicabile solo
				 * nel caso in cui la risposta ha una
				 * dimensione massima nota a priori.
				 */

				/* Leggo lunghezza username */
				if (read_all(ns, len, 2) < 0) {
					perror("read");
					exit(EXIT_FAILURE);
				}

				/* Decodifico lunghezza nomefile come intero unsigned a
				 * 16 bit in formato big endian (AKA network byte
				 * order) */
				nomefile_len = (size_t)len[1] | ((size_t)len[0] << 8);

				/* Inizializzo il buffer nomefile a zero e so che
				 * nomefile_len < sizeof(nomefile), quindi sono sicuro
				 * che il buffer sarà sempre null-terminated. In questo
				 * modo, posso interpretarlo come una stringa C e
				 * passarlo direttamente alla funzione strcmp. */
				memset(nomefile, 0, sizeof(nomefile));
				if (read_all(ns, nomefile, nomefile_len) < 0) {
					perror("read");
					exit(EXIT_FAILURE);
				}

#ifdef USE_LIBUNISTRING
				/* Verifico che il messaggio sia UTF-8 valido */
				if (u8_check((uint8_t *)nomefile, nomefile_len) != NULL) {
					/* Client che malfunziona - inviato messaggio
					 * con stringa UTF-8 non valida */
					fprintf(stderr, "Request is not valid UTF-8!\n");
					close(ns);
					exit(EXIT_SUCCESS);
				}
#endif

				if ((file = open(nomefile, O_RDONLY)) < 0) {
					//non trovo il file, termino il programma
					close(ns);
					exit(EXIT_FAILURE);
				} else {
					close(file);
				}

				/* Leggo lunghezza stringa */
				if (read_all(ns, len, 2) < 0) {
					perror("read");
					exit(EXIT_FAILURE);
				}

				/* Decodifico lunghezza stringa come intero unsigned a
				 * 16 bit in formato big endian (AKA network byte
				 * order) */
				stringa_len = (size_t)len[1] | ((size_t)len[0] << 8);

				/* Inizializzo il buffer stringa a zero e so che
				 * stringa_len < sizeof(stringa), quindi sono sicuro
				 * che il buffer sarà sempre null-terminated. In questo
				 * modo, posso interpretarlo come una stringa C e
				 * passarlo direttamente alla funzione strcmp. */
				memset(stringa, 0, sizeof(stringa));
				if (read_all(ns, stringa, stringa_len) < 0) {
					perror("read");
					exit(EXIT_FAILURE);
				}

#ifdef USE_LIBUNISTRING
				/* Verifico che il messaggio sia UTF-8 valido */
				if (u8_check((uint8_t *)stringa, stringa_len) != NULL) {
					/* Client che malfunziona - inviato messaggio
					 * con stringa UTF-8 non valida */
					fprintf(stderr, "Request is not valid UTF-8!\n");
					close(ns);
					exit(EXIT_SUCCESS);
				}
#endif

                                /* Creo file temporaneo */
                                strcpy(template, "rgrep-tmpfile-XXXXXX");
                                fd = mkstemp(template);
                                if (fd < 0) {
                                        perror("exec");
                                        exit(EXIT_FAILURE);
                                }

                                pid_n = fork();
                                if (pid_n < 0) {
                                        perror("fork");
                                        exit(EXIT_FAILURE);
                                } else if (pid_n == 0) {
                                        /* NIPOTE */

                                        /* Chiudo file descriptor non usati */
                                        close(ns);

                                        /* Redirezione output su pipe */
                                        close(1);
                                        if (dup(fd) < 0) {
                                                perror("dup");
                                                exit(EXIT_FAILURE);
                                        }
                                        close(fd);

					/* Eseguo la grep sul server con i parametri corretti */
					execlp("grep", "grep", stringa, nomefile, (char*)NULL);
					perror("exec grep");
					exit(EXIT_FAILURE);
                                }

                                /* FIGLIO */

				/* Aspetto terminazione nipote per sincerarmi
				 * che abbia scritto tutta la risposta nel file
				 * temporaneo. */
                                waitpid(pid_n, &status, 0);

                                /* Calcolo dimensione del file (ovverosia della risposta) */
                                off_t response_len = lseek(fd, 0, SEEK_END);
                                if (response_len < 0) {
                                        perror("lseek");
                                        exit(EXIT_FAILURE);
                                }

                                if (response_len > UINT16_MAX) {
                                        fprintf(stderr, "Risposta troppo grande!\n");
                                        exit(EXIT_FAILURE);
                                }

                                len[0] = (uint8_t)((response_len & 0xFF00) >> 8);
                                len[1] = (uint8_t)(response_len & 0x00FF);

                                /* Invio dimensione risposta */
                                if (write_all(ns, len, 2) < 0) {
                                        perror("write");
                                        exit(EXIT_FAILURE);
                                }

                                /* Invio la risposta, ovverosia il contenuto del file */
				if (portable_sendfile(fd, ns) < 0) {
                                        perror("portable_sendfile");
                                        exit(EXIT_FAILURE);
                                }

                                /* Rimuovo il file temporaneo */
                                unlink(template);
                                close(fd);
                        }

                        close(ns);
                } 

                /* PADRE */ 

                /* Chiudo la socket attiva */
                close(ns);
        }

        close(sd);

        return 0;
}

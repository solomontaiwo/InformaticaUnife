#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#ifdef USE_LIBUNISTRING
#  include <unistr.h>
#endif
#include "rxb.h"
#include "utils.h"
#include "simple_csexp.h"


/* Gestore del segnale SIGCHLD */
void handler(int signo)
{
        int status;

	(void)signo;

        /* gestisco tutti i figli terminati */
        while (waitpid(-1, &status, WNOHANG) > 0)
		continue;
}


int main(int argc, char** argv)
{
        struct addrinfo hints, *res;
        int err, sd, ns, pid, on;
        struct sigaction sa;

        /* Controllo argomenti */
        if (argc < 2){
                printf("Uso: ./server <porta> \n");
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
        if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))<0){
                perror("setsockopt");
                exit(EXIT_FAILURE);
        }

        if (bind(sd, res->ai_addr, res->ai_addrlen) < 0) {
                perror("Errore in bind");
                exit(EXIT_FAILURE);
        }

        freeaddrinfo(res);

        if (listen(sd, SOMAXCONN) < 0){
                perror("listen");
                exit(EXIT_FAILURE);
        }

        /* Attendo i client... */
        for (;;) {
                printf("Server in ascolto...\n");

                if ((ns = accept(sd, NULL, NULL)) < 0) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                }

                /* Generazione di un figlio */
                if ((pid = fork())<0){
                        perror("fork");
                        exit(EXIT_FAILURE);
                } else if (pid == 0){ /* figlio */
                        rxb_t rxb;

                        /* Chiudo la socket passiva */
                        close(sd);

                        /* Disabilito gestore SIGCHLD */
                        memset(&sa, 0, sizeof(sa));
                        sigemptyset(&sa.sa_mask);
                        sa.sa_handler = SIG_DFL;

                        if (sigaction(SIGCHLD, &sa, NULL) == -1) {
                                perror("sigaction");
                                exit(EXIT_FAILURE);
                        }

                        /* Inizializzo buffer di ricezione */
                        rxb_init(&rxb, 64 * 1024);

                        for (;;) {
                                int i, fd, cc, pid_n1, pid_n2, pipe_n1n2[2], status;
                                char template[256], message[1024], *categoria;
                                off_t file_size;
                                char **strings;
                                size_t strings_len;

                                /* Leggo messaggio richiesta da Client */
                                cc = simple_csexp_read_message(&rxb, ns, &strings, &strings_len);
                                if (cc < 0 || strings_len != 1) {
                                        fprintf(stderr, "Errore lettura messaggio da socket!\n");
                                        exit(EXIT_FAILURE);
                                }

                                /* Il messaggio ha solo una stringa, che è la categoria */
                                categoria = strings[0];

#ifdef USE_LIBUNISTRING
                                /* Verifico che il messaggio sia UTF-8 valido */
                                if (u8_check((uint8_t *)categoria, strlen(categoria)) != NULL) {
                                        /* Client che malfunziona - inviato messaggio
                                         * con stringa UTF-8 non valida */
                                        fprintf(stderr, "Request is not valid UTF-8!\n");
                                        close(ns);
                                        exit(EXIT_SUCCESS);
                                }
#endif

                                /* Creo file temporaneo su cui salverò output sort */
                                strcpy(template, "/tmp/contocorrente-server-XXXXXX");
                                fd = mkstemp(template);
                                if (fd < 0) {
                                        perror("mkstemp");
                                        exit(EXIT_FAILURE);
                                }

                                /* Creo pipe */
                                if (pipe(pipe_n1n2) < 0) {
                                        perror("pipe");
                                        exit(EXIT_FAILURE);
                                }

                                if ((pid_n1 = fork()) < 0){
                                        perror("seconda fork");
                                        exit(EXIT_FAILURE);
                                } else if (pid_n1 == 0){
                                        /* Nipote 1 */

                                        /* Chiudo i descrittori che non servono */
                                        close(fd);
                                        close(ns);
                                        close(pipe_n1n2[0]);

                                        /* Ridireziono stdout */
                                        close(1);
                                        if (dup(pipe_n1n2[1]) < 0) {
                                                perror("dup");
                                                exit(EXIT_FAILURE);
                                        }
                                        close(pipe_n1n2[1]);

                                        /* Eseguo la grep mandando i risultati al figlio */
                                        /* uso "test.txt" al posto di "/var/local/conto_corrente.txt" */
                                        execlp("grep", "grep", categoria, "test.txt", (char*)NULL);
                                        perror("execlp grep");
                                        exit(EXIT_FAILURE);
                                }

				/* simple_csexp_read_message alloca memoria, che devo liberare
				 * manualmente quando non mi serve più. (In realtà il messaggio
				 * dovrebbe avere solo una stringa, ma faccio comunque un
				 * ciclo.) */
                                for (i = 0; i < strings_len; ++i) {
					free(strings[i]);
				}
				free(strings);

                                if ((pid_n2 = fork()) < 0){
                                        perror("seconda fork");
                                        exit(EXIT_FAILURE);
                                } else if (pid_n2 == 0){
                                        /* Nipote 2 */

                                        /* Chiudo descrittori non necessari */
                                        close(ns);
                                        close(pipe_n1n2[1]);

                                        /* Ridireziono stdin */
                                        close(0);
                                        if (dup(pipe_n1n2[0]) < 0) {
                                                perror("dup");
                                                exit(EXIT_FAILURE);
                                        }
                                        close(pipe_n1n2[0]);

                                        /* Ridireziono stdout */
                                        close(1);
                                        if (dup(fd) < 0) {
                                                perror("dup");
                                                exit(EXIT_FAILURE);
                                        }
                                        close(fd);

                                        execlp("sort", "sort", "-r", "-n", (char*)NULL);
                                        perror("execlp sort");
                                        exit(EXIT_FAILURE);
                                }

                                /* Figlio */

                                /* Chiudo descrittori non necessari */
                                close(pipe_n1n2[0]);
                                close(pipe_n1n2[1]);

                                /* Aspetto terminazione figli */
                                waitpid(pid_n1, &status, 0);
                                waitpid(pid_n2, &status, 0);

                                /* Calcolo dimensione file */
                                file_size = lseek(fd, 0, SEEK_END);
                                if (file_size < 0) {
                                        perror("lseek");
                                        exit(EXIT_FAILURE);
                                }

				if (file_size == 0) {
					cc = write(ns, "()", 2);
					if (cc <= 0) {
						perror("write");
						exit(EXIT_FAILURE);
					}
				} else {
					/* Preparo prima parte del messaggio */
					snprintf(message, sizeof(message), "(%ld:", (long)file_size);

					/* E la trasmetto al Client */
					cc = write_all(ns, message, strlen(message));
					if (cc <= 0) {
						perror("write");
						exit(EXIT_FAILURE);
					}

					/* Mando contenuto file temporaneo al Client */
					cc = portable_sendfile(fd, ns);
					if (cc < 0) {
						perror("sendfile");
						exit(EXIT_FAILURE);
					}

					/* Chiudo il messaggio */
					cc = write(ns, ")", 1);
					if (cc <= 0) {
						perror("write");
						exit(EXIT_FAILURE);
					}
				}

                                /* Rimuovo file temporaneo */
                                unlink(template);
                                close(fd);
                        }

                        close(ns);
                        exit(EXIT_SUCCESS);
                }

                /* padre */
                close(ns);
        }

        return 0;
}

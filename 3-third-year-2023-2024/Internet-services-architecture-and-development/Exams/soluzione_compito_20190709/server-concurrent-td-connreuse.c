#include <sys/socket.h>
#include <sys/wait.h>
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include "rxb.h"
#include "utils.h"

/* Massima lunghezza stringhe: 64 KiB */
#define MAX_REQUEST_SIZE 4096

/* Implementazione funzione autorizza */
int autorizza(const char *username, const char *password)
{
	return 1;
}

/* Gestore del segnale SIGCHLD */
void handler(int signo)
{
        int status;

        (void)signo; /* per evitare warning */

        /* eseguo wait non bloccanti finché ho dei figli terminati */
        while (waitpid(-1, &status, WNOHANG) > 0)
                continue;
}

/* argv[0] argv[1] */
/* server  porta */
int main (int argc, char *argv[])
{
	int err, sd, on;
	struct addrinfo hints, *res;
        struct sigaction sa = { 0 };

	/* Controllo argomenti */
	if (argc != 2) {
		exit(EXIT_FAILURE);
	}

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
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	err = getaddrinfo(NULL, argv[1], &hints, &res);
	if (err != 0) {
		exit(EXIT_FAILURE);
	}

	sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (sd < 0) {
		exit(EXIT_FAILURE);
	}

        on = 1;
        if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0){
                perror("setsockopt");
                exit(EXIT_FAILURE);
        }

	err = bind(sd, res->ai_addr, res->ai_addrlen);
	if (err < 0) {
		exit(EXIT_FAILURE);
	}

	err = listen(sd, SOMAXCONN);
	if (err < 0) {
		exit(EXIT_FAILURE);
	}

	while (1) {
		int ns, pid_f;

		ns = accept(sd, NULL, NULL);
		if (ns < 0) {
			if (errno == EINTR) {
				continue;
			} else {
				exit(EXIT_FAILURE);
			}
		}

		pid_f = fork();
		if (pid_f < 0) {
			exit(EXIT_FAILURE);
		} else if (pid_f == 0) {
			/* FIGLIO */
			rxb_t rxb;
                        char username[MAX_REQUEST_SIZE];
                        char password[MAX_REQUEST_SIZE];
                        char categoria[MAX_REQUEST_SIZE];
			size_t username_len, password_len, categoria_len;

			close(sd);

			/* creo buffer rxb */
			rxb_init(&rxb, MAX_REQUEST_SIZE * 2);

			/* disinstallo gestore segnali */
			signal(SIGCHLD, SIG_DFL);

			/* ciclo di richieste */
			while (1) {
				char *end_request = "--- END REQUEST ---\n";
				int pid_cut, pid_sort, pid_head, status;
				int pipe_cs[2], pipe_sh[2];

				/* leggere 3 informazioni */
				memset(username, 0, sizeof(username));
				username_len = sizeof(username) - 1;
				err = rxb_readline(&rxb, ns, username, &username_len);
				if (err < 0) {
					exit(EXIT_FAILURE);
				}

				memset(password, 0, sizeof(password));
				password_len = sizeof(password) - 1;
				err = rxb_readline(&rxb, ns, password, &password_len);
				if (err < 0) {
					exit(EXIT_FAILURE);
				}

				memset(categoria, 0, sizeof(categoria));
				categoria_len = sizeof(categoria) - 1;
				err = rxb_readline(&rxb, ns, categoria, &categoria_len);
				if (err < 0) {
					exit(EXIT_FAILURE);
				}

				/* chiamare autorizza */
				if (autorizza(username, password) != 1) {
					char *unauthorized = "Non autorizzato!\n";
					write_all(ns, unauthorized, strlen(unauthorized));
					write_all(ns, end_request, strlen(end_request));
					continue;
				}

				if (pipe(pipe_cs) < 0) {
					exit(EXIT_FAILURE);
				}

				/* creo nipoti */
				pid_cut = fork();
				if (pid_cut < 0) {
					exit(EXIT_FAILURE);
				} else if (pid_cut == 0) {
					char nomefile[MAX_REQUEST_SIZE + 256];

					/* NIPOTE CUT */
					close(ns);
					close(1);
					dup(pipe_cs[1]);
					close(pipe_cs[1]);
					close(pipe_cs[0]);

					/*
					snprintf(nomefile, sizeof(nomefile), 
						"/var/local/macchine_caffé/%s.txt", categoria);
					*/
					snprintf(nomefile, sizeof(nomefile), 
						"%s.txt", categoria);
					/* strcpy(nomefile, categoria); strcat(nomefile, ".txt"); */

					execlp("cut", "cut", "-d", ",", "-f", "1,3,4", nomefile, NULL);
					perror("exec");
					exit(EXIT_FAILURE);
				}

				if (pipe(pipe_sh) < 0) {
					exit(EXIT_FAILURE);
				}

				pid_sort = fork();
				if (pid_sort < 0) {
					exit(EXIT_FAILURE);
				} else if (pid_sort == 0) {
					/* NIPOTE SORT */
					close(ns);

					close(0);
					dup(pipe_cs[0]);
					close(pipe_cs[1]);
					close(pipe_cs[0]);

					close(1);
					dup(pipe_sh[1]);
					close(pipe_sh[1]);
					close(pipe_sh[0]);

					execlp("sort", "sort", "-rn", NULL);
					perror("exec");
					exit(EXIT_FAILURE);
				}

				pid_head = fork();
				if (pid_head < 0) {
					exit(EXIT_FAILURE);
				} else if (pid_head == 0) {
					/* NIPOTE HEAD */
					close(pipe_cs[1]);
					close(pipe_cs[0]);

					close(0);
					dup(pipe_sh[0]);
					close(pipe_sh[1]);
					close(pipe_sh[0]);

					close(1);
					dup(ns);
					close(ns);

					execlp("head", "head", "-n", "10", NULL);
					perror("exec");
					exit(EXIT_FAILURE);
				}

				/* chiudo pipe che non use il figlio */
				close(pipe_cs[1]);
				close(pipe_cs[0]);
				close(pipe_sh[1]);
				close(pipe_sh[0]);

				/* aspetto terminazione nipoti */
				waitpid(pid_cut, &status, 0); 
				waitpid(pid_sort, &status, 0); 
				waitpid(pid_head, &status, 0); 

				/* mando stringa fine richiesta */
				write_all(ns, end_request, strlen(end_request));
			}

			/* cleanup */
			close(ns);
			rxb_destroy(&rxb);
			exit(EXIT_SUCCESS);
		}

		/* PADRE */
		close(ns);
	}

	close(sd);

	return 0;
}

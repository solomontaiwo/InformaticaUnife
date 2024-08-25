#define _POSIX_C_SOURCE 200809L
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include "rxb.h"
#include "utils.h"

#define MAX_REQUEST_SIZE (16 * 1024)

void sigchld_handler(int signo)
{
	int status;

	(void)signo;

	while(waitpid(-1, &status, WNOHANG) > 0)
		continue;
}

/* server  porta */
/* argv[0] argv[1] */
int main(int argc, char *argv[])
{
	int err, sd, opt;
	struct addrinfo hints, *res;
	struct sigaction sa;

	/* Controllo errori */
	if (argc != 2) {
		fprintf(stderr, "Error! Usage:\n\t%s porta\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* Ripristiniamo semantica sensata pipe e socket */
	memset(&sa, 0, sizeof(sa));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = SIG_IGN;

	if (sigaction(SIGPIPE, &sa, NULL) == -1) {
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	/* Installiamo gestore SIGCHLD */
	memset(&sa, 0, sizeof(sa));
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = sigchld_handler;

	if (sigaction(SIGCHLD, &sa, NULL) == -1) {
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	/* Preparo chiamata getaddrinfo */
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	char *service = argv[1];

	err = getaddrinfo(NULL, service, &hints, &res);
	if (err != 0) {
		fprintf(stderr, "Errore getaddrinfo: %s\n", gai_strerror(err));
		exit(EXIT_FAILURE);
	}

	sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (sd < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	opt = 1;
	err = setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	if (err < 0) {
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}

	err = bind(sd, res->ai_addr, res->ai_addrlen);
	if (err < 0) {
		perror("bind");
		exit(EXIT_FAILURE);
	}

	freeaddrinfo(res);

	err = listen(sd, SOMAXCONN);
	if (err < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}

	for(;;) {
		int ns, pid;

		ns = accept(sd, NULL, NULL);
		if (ns < 0)
			continue;

		pid = fork();
		if (pid < 0) {
			perror("fork 1");
			exit(EXIT_FAILURE);
		} else if (pid == 0) { 
			/* FIGLIO */
			int pid_n1, pid_n2, pipe_n1n2[2], status;
			rxb_t rxb;
			char tipo_sensore[4096];
			char stanza_sensore[4096];
			char numero_letture[4096];
			size_t tipo_sensore_len;
			size_t stanza_sensore_len;
			size_t numero_letture_len;
			char *end_response = "--- END RESPONSE ---\n";

			/* Chiudo socket passiva */
			close(sd);

			/* Disabilitiamo gestore SIGCHLD */
			memset(&sa, 0, sizeof(sa));
			sigemptyset(&sa.sa_mask);
			sa.sa_handler = SIG_DFL;

			if (sigaction(SIGCHLD, &sa, NULL) == -1) {
				perror("sigaction");
				exit(EXIT_FAILURE);
			}

			/* Inizializzo il buffer per la readline */
			rxb_init(&rxb, MAX_REQUEST_SIZE * 2);

			/* Leggo tipo_sensore dal Client */
			memset(tipo_sensore, 0, sizeof(tipo_sensore));
			tipo_sensore_len = sizeof(tipo_sensore) - 1;
			err = rxb_readline(&rxb, ns, tipo_sensore, &tipo_sensore_len);
			if (err < 0) {
				perror("Errore rxb_readline");
				exit(EXIT_FAILURE);
			}

#ifdef USE_LIBUNISTRING
			if (u8_check((uint8_t *)tipo_sensore, tipo_sensore_len) != NULL) {
				fputs("Errore: testo UTF-8 non valido!", stderr);
				exit(EXIT_FAILURE);
			}
#endif /* USE_LIBUNISTRING */

			/* Leggo stanza_sensore dal Client */
			memset(stanza_sensore, 0, sizeof(stanza_sensore));
			stanza_sensore_len = sizeof(stanza_sensore) - 1;
			err = rxb_readline(&rxb, ns, stanza_sensore, &stanza_sensore_len);
			if (err < 0) {
				perror("Errore rxb_readline");
				exit(EXIT_FAILURE);
			}

#ifdef USE_LIBUNISTRING
			if (u8_check((uint8_t *)stanza_sensore, stanza_sensore_len) != NULL) {
				fputs("Errore: testo UTF-8 non valido!", stderr);
				exit(EXIT_FAILURE);
			}
#endif /* USE_LIBUNISTRING */

			/* Leggo numero_letture dal Client */
			memset(numero_letture, 0, sizeof(numero_letture));
			numero_letture_len = sizeof(numero_letture) - 1;
			err = rxb_readline(&rxb, ns, numero_letture, &numero_letture_len);
			if (err < 0) {
				perror("Errore rxb_readline");
				exit(EXIT_FAILURE);
			}

#ifdef USE_LIBUNISTRING
			if (u8_check((uint8_t *)numero_letture, numero_letture_len) != NULL) {
				fputs("Errore: testo UTF-8 non valido!", stderr);
				exit(EXIT_FAILURE);
			}
#endif /* USE_LIBUNISTRING */

			/* Creo la pipe */
			err = pipe(pipe_n1n2);
			if (err < 0) {
				perror("pipe");
				exit(EXIT_FAILURE);
			}

			/* Genero primo nipote */
			pid_n1 = fork();
			if (pid_n1 < 0) {
				perror("fork 2");
				exit(EXIT_FAILURE);
			} else if (pid_n1 == 0) { 
				/* NIPOTE 1 */
				char nomefile[4096];

				/* Non posso usare il percorso /var/letture, per cui uso ./letture */
				snprintf(nomefile, sizeof(nomefile), "./letture/%s.txt", stanza_sensore);
				/* Redirigo standard output su pipe */
				close(1);
				if(dup(pipe_n1n2[1]) < 0) {
					perror("dup");
					exit(EXIT_FAILURE);
				}
				close(pipe_n1n2[1]);

				/* Chiudo file descriptor non utilizzati */
				close(ns);
				close(pipe_n1n2[0]);

				execlp("grep", "grep", tipo_sensore, nomefile, NULL);
				perror("execlp nipote 1");
				exit(EXIT_FAILURE);
			}

			/* Genero secondo nipote */
			pid_n2 = fork();
			if (pid_n2 < 0) {
				perror("fork 3");
				exit(EXIT_FAILURE);
			} else if (pid_n2 == 0) { 
				/* NIPOTE 2 */

				/* Redirigo standard input dalla pipe */
				close(0);
				if(dup(pipe_n1n2[0]) < 0) {
					perror("dup");
					exit(EXIT_FAILURE);
				}
				close(pipe_n1n2[0]);

				/* Redirigo standard output su pipe */
				close(1);
				if(dup(ns) < 0) {
					perror("dup");
					exit(EXIT_FAILURE);
				}
				close(ns);

				/* Chiudo file descriptor non utilizzati */
				close(pipe_n1n2[1]);

				execlp("tail", "tail", "-n", numero_letture, NULL);
				perror("execlp nipote 2");
				exit(EXIT_FAILURE);
			}

			/* FIGLIO */

			/* Chiudo file descriptor non utilizzati */
			close(pipe_n1n2[0]);
			close(pipe_n1n2[1]);

			/* Attendo terminazione nipoti */
			waitpid(pid_n1, &status, 0);
			waitpid(pid_n2, &status, 0);

			err = write_all(ns, end_response, strlen(end_response));
			if (err < 0) {
				perror("write_all");
				exit(EXIT_FAILURE);
			}
		}

		/* PADRE */
		close(ns);
	}

	close(sd);

	return 0;
}

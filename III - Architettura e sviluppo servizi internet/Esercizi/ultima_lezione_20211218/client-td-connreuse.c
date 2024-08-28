#include <sys/socket.h>
#define _POSIX_C_SOURCE 200809L
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"
#include "rxb.h"

#define DIM 80
#define MAX_REQUEST_SIZE 4096

/* 
 *		   argv[1] argv[2]
 * coffee_machines server  porta 
 */
int main (int argc, char *argv[])
{ 
	int err, sd;
	struct addrinfo hints, *res, *ptr;
	rxb_t rxb;

	if (argc != 3) {
		fprintf(stderr, "Usage: coffee_machines server porta\n");
		exit(EXIT_FAILURE);
	}

	/* chiamata DNS */
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	err = getaddrinfo(argv[1], argv[2], &hints, &res);
	if (err != 0) {
		exit(EXIT_FAILURE);
	}

	/* procedura di connessione */
	for (ptr = res; ptr != NULL; ptr = ptr->ai_next) {
		sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (sd < 0)
			continue;
		
		err = connect(sd, ptr->ai_addr, ptr->ai_addrlen);
		if (err == 0) 
			break;

		close(sd);
	}

	if (ptr == NULL) {
		exit(EXIT_FAILURE);
	}

	freeaddrinfo(res);

	rxb_init(&rxb, MAX_REQUEST_SIZE * 2);

	/* ciclo di servizio */
	while (1) {
		char username[DIM];
		char password[DIM];
		char categoria_macchine[DIM];
		char line[4096];

		puts("Inserisci username:");
		if (fgets(username, sizeof(username), stdin) == NULL) {
			exit(EXIT_FAILURE);
		}

		puts("Inserisci password:");
		if (fgets(password, sizeof(password), stdin) == NULL) {
			exit(EXIT_FAILURE);
		}

		puts("Inserisci categoria macchine:");
		if (fgets(categoria_macchine, sizeof(categoria_macchine), stdin) == NULL) {
			exit(EXIT_FAILURE);
		}

		if (write_all(sd, username, strlen(username)) < 0) {
			exit(EXIT_FAILURE);
		}
				
		if (write_all(sd, password, strlen(password)) < 0) {
			exit(EXIT_FAILURE);
		}

		if (write_all(sd, categoria_macchine, strlen(categoria_macchine)) < 0) {
			exit(EXIT_FAILURE);
		}

		while (1) {
			size_t buflen = sizeof(line)-1;

			memset(line, 0, sizeof(line));
			
			err = rxb_readline(&rxb, sd, line, &buflen);
			if (err < 0) {
				exit(EXIT_FAILURE);
			}

			if (strcmp(line, "--- END REQUEST ---") == 0)
				break;

			puts(line);
			/* printf("%s\n", line); */
			/* write_all(STDOUT_FILENO, line, buflen); write(STDOUT_FILENO, "\n", 1); */
		}

	}

	rxb_destroy(&rxb);

	close(sd);
	
	return 0;
}

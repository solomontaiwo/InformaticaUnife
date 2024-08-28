#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define DIM_FILEPATH 200
#define DIM_SPETTACOLO 200
#define DIM_RIS 2048
#define ROOT_PATH "/home/studente"

static volatile sig_atomic_t count = 0;

void handler() {
	printf("numero di richieste servite: %d\n", count);
	exit(0);
}

int main(int argc, char *argv[])
{
	int fd, n, p1p2[2], p2p3[2], p0p3[2], pid, status, nread;
	char filepath[DIM_FILEPATH], spettacolo[DIM_SPETTACOLO], ris[DIM_RIS];

	// controllo che il numero di parametri sia corretto
	if (argc != 2) {
		printf("errore: numero sbagliato di parametri\n");
		printf("usage: trova_spettacoli <nomeTeatro>\n");
		exit(1);
	}

	// controllo che <nomeTeatro> esista
	sprintf(filepath, "%s/%s.txt", ROOT_PATH, argv[1]);
	fd = open(filepath, O_RDONLY);
	if (fd < 0) {
		perror("P0: open");
		exit(2);
	}
	close(fd);

	// imposto la gestione il segnale Ctrl-C
	signal(SIGINT, handler);	

	while (1) {
		printf("inserire nome spettacolo: ");
		scanf("%s", spettacolo);

		printf("inserire numero di spettacoli: ");
		scanf("%d", &n);

		// esco dal ciclo se <n> uguale a 0
		// ritorno un warning se <n> è negativo
		if (n == 0) {
			break;
		} else if (n < 0) {
			printf("warning: <n> intero negativo\n");
			continue;
		}

		// creo pipe per comunicazione tra P1 e P2
		if (pipe(p1p2) < 0) {
			perror("P0: pipe p1p2");
			exit(3);
		}

		pid = fork();
		if (pid < 0) {
			perror("P0: fork P1");
			exit(4);
		}
		if (pid == 0) {
			/*
				codice P1
			*/
			// imposto gestione default di SIGINT
			signal(SIGINT, SIG_DFL);

			// chiudo pipe non necessarie
			close(p1p2[0]);

			// redirigo stdout
			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);

			// seleziono gli spettacoli di interesse
			execlp("grep", "grep", spettacolo, filepath, (char *)0);
			perror("P1: grep");
			exit(5);
		}

		// creo pipe per comunicazione tra P2 e P3
		if (pipe(p2p3) < 0) {
			perror("P0: pipe p2p3");
			exit(6);
		}

		pid = fork();
		if (pid < 0) {
			perror("P0: fork P2");
			exit(7);
		}
		if (pid == 0) {
			/*
				codice P2
			*/

			// imposto gestione default di SIGINT
			signal(SIGINT, SIG_DFL);

			// chiudo pipe non necessarie
			close(p1p2[1]);
			close(p2p3[0]);

			// redirigo stdin
			close(0);
			dup(p1p2[0]);
			close(p1p2[0]);

			// redirigo stdout
			close(1);
			dup(p2p3[1]);
			close(p2p3[1]);

			// ordino gli spettacoli di interesse
			execlp("sort", "sort", "-n", (char *)0);
			perror("P2: sort");
			exit(8);
		}

		// creo pipe per comunicazione tra P0 e P3
		if (pipe(p0p3) < 0) {
			perror("P0: pipe p0p3");
			exit(9);
		}

		pid = fork();
		if (pid < 0) {
			perror("P0: fork P3");
			exit(10);
		}
		if (pid == 0) {
			/*
				codice P3
			*/
			char str_n[4];

			// imposto gestione default di SIGINT
			signal(SIGINT, SIG_DFL);

			// chiudo pipe non necessarie
			close(p1p2[0]);
			close(p1p2[1]);
			close(p2p3[1]);
			close(p0p3[0]);

			// redirigo stdin
			close(0);
			dup(p2p3[0]);
			close(p2p3[0]);

			// redirigo stdout
			close(1);
			dup(p0p3[1]);
			close(p0p3[1]);
			
			// seleziono i primi <n> spettacoli
			sprintf(str_n, "%d", n);
			execlp("head", "head", "-n", str_n, (char *)0);
			perror("P3: head");
			exit(11);
		}

		// chiudo pipe tra P1 e P2
		close(p1p2[0]);
		close(p1p2[1]);

		// chiudo pipe tra P2 e P3
		close(p2p3[0]);
		close(p2p3[1]);

		// chiudo pipe tra P0 e P3 lato scrittura
		close(p0p3[1]);

		// attendo terminazione di P1, P2 e P3
		wait(&status);
		wait(&status);
		wait(&status);

		// leggo i risultati
		nread = read(p0p3[0], ris, sizeof(ris) - 1);
		if (nread < 0) {
			perror("P0: read");
			exit(12);
		}

		// chiudo pipe tra P0 e P3 lato lettura
		close(p0p3[0]);

		// stampo i risultati
		ris[nread] = '\0';
		printf("%s\n", ris);

		// incremento contatore richieste servite
		count++;
	}

	printf("numero di richieste servite: %d\n", count);
	return 0;
}

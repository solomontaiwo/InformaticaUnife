#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define DIM_FILEPATH 200
#define DIM_DATE 32
#define DIM_STR_N 20
#define ROOT_PATH "/var/local/ticket"

static volatile sig_atomic_t count = 0;

void handler() {
	printf("numero di richieste servite: %d\n", count);
	exit(0);
}

int main(int argc, char *argv[])
{
	int fd, n, gg, mm, yyyy, p1p2[2], p2p3[2], pid, status;
	char filepath[DIM_FILEPATH], date[DIM_DATE];

	// controllo che il numero di parametri sia corretto
	if (argc != 3) {
		printf("errore: numero sbagliato di parametri\n");
		printf("usage: trova_biglietti <destinazione> <n>\n");
		exit(1);
	}

	// controllo che <n> sia un intero positivo
	if ((n = atoi(argv[2])) <= 0) {
		printf("errore: <n> deve essere un intero positivo\n");
		exit(2);
	}

	// controllo che <destinazione> esista
	sprintf(filepath, "%s/%s.txt", ROOT_PATH, argv[1]);
	fd = open(filepath, O_RDONLY);
	if (fd < 0) {
		perror("P0: open");
		exit(3);
	}
	close(fd);

	// imposto la gestione il segnale Ctrl-C
	signal(SIGINT, handler);	

	while (1) {
		// chiedo <giorno>, <mese> e <anno>
		printf("inserire giorno, mese e anno (GG MM YYYY): ");
		scanf("%d %d %d", &gg, &mm, &yyyy);

		if (gg == -1 || mm == -1 || yyyy == -1)
			break;
		else if (gg < 0 || mm < 0 || yyyy < 0) {
			printf("errore: inserire interi positivi\n");
			continue;
		} else if (gg < 1 || gg > 31) {
			printf("errore: inserire <giorno> compreso tra 0 e 31\n");
			continue;
		} else if (mm < 1 || mm > 12) {
			printf("errore: inserire <mese> compreso tra 0 e 12\n");
			continue;
		}

		sprintf(date, "%02d%02d%04d", gg, mm, yyyy);

		// creo pipe per comunicazione tra P1 e P2
		if (pipe(p1p2) < 0) {
			perror("P0: pipe p1p2");
			exit(4);
		}

		// creo pipe per comunicazione tra P2 e P3
		if (pipe(p2p3) < 0) {
			perror("P0: pipe p2p3");
			exit(5);
		}

		pid = fork();
		if (pid < 0) {
			perror("P0: fork P1");
			exit(6);
		}
		if (pid == 0) {
			/*
				codice P1
			*/

			// imposto gestione default di SIGINT
			signal(SIGINT, SIG_DFL);

			// chiudo pipe tra P2 e P3
			close(p2p3[0]);
			close(p2p3[1]);

			// chiudo pipe tra P1 e P2 lato lettura
			close(p1p2[0]);

			// redirigo stdout
			close(1);
			dup(p1p2[1]);

			// chiudo pipe tra P1 e P2 lato scrittura
			close(p1p2[1]);

			// seleziono biglietti disponibili in GGMMYYYY
			execlp("grep", "grep", date, filepath, (char *)0);
			perror("P1: grep");
			exit(7);
		}

		pid = fork();
		if (pid < 0) {
			perror("P0: fork P2");
			exit(8);
		}
		if (pid == 0) {
			/*
				codice P2
			*/

			// imposto gestione default di SIGINT
			signal(SIGINT, SIG_DFL);

			// chiudo pipe tra P1 e P2 lato scrittura
			close(p1p2[1]);

			// chiudo pipe tra P2 e P2 lato lettura
			close(p2p3[0]);

			// redirigo lo stdin
			close(0);
			dup(p1p2[0]);

			// chiudo pipe tra P1 e P2 lato lettura
			close(p1p2[0]);

			// redirigo stdout
			close(1);
			dup(p2p3[1]);

			// chiudo pipe tra P2 e P3 lato scrittura
			close(p2p3[1]);

			// ordino i biglietti dal più economico
			execlp("sort", "sort", "-n", (char *)0);
			perror("P2: sort");
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
			char str_n[DIM_STR_N];

			// imposto gestione default di SIGINT
			signal(SIGINT, SIG_DFL);

			// chiudo pipe tra P1 e P2
			close(p1p2[0]);
			close(p1p2[1]);

			// redirigo stdin
			close(0);
			dup(p2p3[0]);

			// chiudo pipe tra P2 e P3
			close(p2p3[0]);
			close(p2p3[1]);

			// visualizza i primi <n> biglietti
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

		// attendo terminazione di P1, P2 e P3
		wait(&status);
		wait(&status);
		wait(&status);

		// incremento contatore richieste servite
		count++;
	}

	printf("numero di richieste servite: %d\n", count);
	return 0;
}

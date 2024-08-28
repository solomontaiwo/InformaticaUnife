// interfaccia: trova_biglietti destinazione N
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#define DIR "/var/local/ticket"
#define SIZE 80

static volatile sig_atomic_t richieste = 0;

void handler()
{
	printf("Numero richieste servite: %d\n", richieste);
	exit(0);
}

int main(int argc, char **argv)
{
	int gg, mm, yyyy;
	int N_offerte;
	char filepath[SIZE], data[SIZE];
	int p1p2[2], p2p3[2], pid, status, fd;

	if (argc != 3)
	{
		fprintf(stderr, "Errore argomenti. Uso %s <destinazione> <N>\n", argv[0]);
		exit(1);
	}

	N_offerte = atoi(argv[2]);

	if (N_offerte <= 0)
	{
		fprintf(stderr, "Errore, <N> deve essere un numero maggiore di zero\n");
		exit(2);
	}

	sprintf(filepath, "%s/%s.txt", DIR, argv[1]);

	if ((fd = open(filepath, O_RDONLY)) < 0)
	{
		fprintf(stderr, "Errore apertura file %s\n", filepath);
		exit(3);
	}
	close(fd);

	signal(SIGINT, handler);

	while (1)
	{
		printf("Inserire giorno, mese e anno (GG MM YYYY): ");
		scanf("%d %d %d", &gg, &mm, &yyyy);

		if (gg == -1 || mm == -1 || yyyy == -1)
		{
			break;
		}
		else if (gg < 0 || mm < 0 || yyyy < 0)
		{
			printf("Errore: inserire interi positivi\n");
			continue;
		}
		else if (gg < 1 || gg > 31)
		{
			printf("Errore: inserire <giorno> compreso tra 0 e 31\n");
			continue;
		}
		else if (mm < 1 || mm > 12)
		{
			printf("Errore: inserire <mese> compreso tra 1 e 12\n");
			continue;
		}

		sprintf(data, "%02d%02d%04d", gg, mm, yyyy);

		if (pipe(p1p2) < 0)
		{
			perror("Errore pipe p1p2");
			exit(4);
		}

		if (pipe(p2p3) < 0)
		{
			perror("Errore pipe p2p3");
			exit(5);
		}

		if ((pid = fork()) < 0)
		{
			perror("P0: errore fork P1");
			exit(6);
		}

		if (pid == 0)
		{
			// codice P1
			signal(SIGINT, SIG_DFL);

			close(p2p3[0]);
			close(p2p3[1]);

			close(p1p2[0]);

			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);

			execlp("grep", "grep", data, filepath, (char *)0);
			perror("Errore P1 grep");
			exit(7);
		}

		if ((pid = fork()) < 0)
		{
			perror("P0: errore fork P2");
			exit(8);
		}

		if (pid == 0)
		{
			// codice P2
			signal(SIGINT, SIG_DFL);

			close(p1p2[1]);
			close(p2p3[0]);

			close(0);
			dup(p1p2[0]);
			close(p1p2[0]);

			close(1);
			dup(p2p3[1]);
			close(p2p3[1]);

			execlp("sort", "sort", "-n", (char *)0);
			perror("P2: sort");
			exit(9);
		}

		if ((pid = fork()) < 0)
		{
			perror("P0: errore fork P3");
			exit(10);
		}

		if (pid == 0)
		{
			// codice P3
			char str_n[SIZE];

			signal(SIGINT, SIG_DFL);

			close(p1p2[1]);
			close(p1p2[0]);

			close(0);
			dup(p2p3[0]);
			close(p2p3[0]);

			close(p2p3[1]);
			close(p2p3[0]);

			sprintf(str_n, "%d", N_offerte);
			execlp("head", "head", "-n", str_n, (char *)0);
		}

		close(p1p2[0]);
		close(p1p2[1]);

		close(p2p3[0]);
		close(p2p3[1]);

		wait(&status);
		wait(&status);
		wait(&status);

		richieste++;
	}

	printf("Numero di richieste servite: %d\n", richieste);
}
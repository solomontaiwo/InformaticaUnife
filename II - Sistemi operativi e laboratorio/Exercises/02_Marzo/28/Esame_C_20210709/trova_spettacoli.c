#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

#define DIM_PATH 256
#define DIM 50
#define ROOT_PATH "/home/utente"

static volatile sig_atomic_t numero_richieste = 0;

void handler()
{
	printf("Numero di richieste servite: %d\n", numero_richieste);
	exit(0);
}

int main(int argc, char **argv)
{
	int fd, status, p1p2[2], p2p3[2], p3p0[2], pid1, pid2, pid3, n_spettacoli, nread;
	char filepath[DIM_PATH], data[DIM], spettacolo[DIM], ris[DIM];

	if (argc != 2)
	{
		fprintf(stderr, "Errore: uso %s <nomeTeatro>\n", argv[0]);
		exit(1);
	}

	if (argv[1][0] == '/')
	{
		fprintf(stderr, "Errore: <nomeTeatro> deve essere una stringa\n");
		exit(2);
	}

	sprintf(filepath, "%s/%s.txt", ROOT_PATH, argv[1]);

	if ((fd = open(filepath, O_RDONLY)) < 0)
	{
		fprinst(stderr, "Errore apertura file %s\n", filepath);
		exit(3);
	}
	close(fd);

	signal(SIGINT, handler);

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

	if (pipe(p3p0) < 0)
	{
		perror("Errore pipe p3p0");
		exit(6);
	}

	printf("Inserisci il nome dello spettacolo: ");
	scanf("%s", spettacolo);

	printf("Inserisci numero di spettacoli N: ");
	scanf("%d", &n_spettacoli);

	while (1)
	{
		if ((pid1 = fork) < 0)
		{
			perror("P0: errore creazione P1");
			exit(7);
		}

		if (pid1 == 0)
		{
			// codice P1
			signal(SIGINT, SIG_DFL);

			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);

			execlp("grep", "grep", spettacolo, filepath, (char *)0);
			perror("Errore grep P1");
			exit(8);
		}

		if ((pid2 = fork()) < 0)
		{
			perror("P0: errore creazione P2");
			exit(9);
		}

		if (pid2 == 0)
		{
			// codice P2
			close(0);
			dup(p1p2[0]);
			close(p1p2[0]);

			close(1);
			dup(p2p3[1]);
			close(p2p3[1]);

			execlp("sort", "sort", "-n", (char *)0);
			perror("P1: errore sort");
			exit(10);
		}

		if ((pid3 = fork()) < 0)
		{
			perror("P0: errore creazione P3");
			exit(11);
		}

		if (pid3 == 0)
		{
			// codice P3
			char str_n[3];

			close(0);
			dup(p2p3[0]);
			close(p2p3[0]);

			close(1);
			dup(p2p3[1]);
			close(p2p3[1]);

			sprintf(str_n, "%d", n_spettacoli);

			execlp("head", "head", "-n", str_n, (char *)0);
			perror("P3: errore head");
			exit(12);
		}

		close(p1p2[0]);
		close(p1p2[1]);

		close(p2p3[0]);
		close(p2p3[1]);

		close(p3p0[1]);

		wait(&status);
		wait(&status);
		wait(&status);

		nread = read(p3p0[0], ris, sizeof(ris) - 1);
		if (nread < 0)
		{
			perror("P0: errore read");
			exit(13);
		}

		close(p3p0[0]);

		ris[nread] = '\0';
		printf("%s\n", ris);

		numero_richieste++;

		printf("Inserisci il nome dello spettacolo: ");
		scanf("%s", spettacolo);

		printf("Inserisci numero di spettacoli N: ");
		scanf("%d", &n_spettacoli);
	}

	printf("numero di richieste servite: %d\n", numero_richieste);
	return 0;
}
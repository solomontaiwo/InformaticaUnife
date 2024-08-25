// interfaccia: trova_spettacoli nomeTeatro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define ROOT_PATH "/home/utente"
#define DIM 50
#define DIM_RIS 1024

static volatile sig_atomic_t numero_richieste = 0;

void ctrlHandler()
{
	printf("Numero di richieste eseguite: %d\n", numero_richieste);
	exit(0);
}

int main(int argc, char **argv)
{
	int fd, pid1, pid2, pid3, p1p2[2], p2p3[2], p3p0[2], n_spettacoli, status, nread;
	char nome_spettacolo[DIM], filepath[DIM], ris[DIM_RIS];

	if (argc != 2)
	{
		fprintf(stderr, "Errore argomenti: uso %s <nomeTeatro>\n", argv[0]);
		exit(1);
	}

	if (argv[1][0] == '/')
	{
		fprintf(stderr, "Errore: <nomeTeatro> deve essere una stringa\n");
		exit(2);
	}

	signal(SIGINT, ctrlHandler);

	sprintf(filepath, "%s/%s.txt", ROOT_PATH, argv[1]);
	if ((fd = open(filepath, O_RDONLY)) < 0)
	{
		fprintf(stderr, "Errore: impossibile aprire il file %s\n", filepath);
		exit(2);
	}
	close(fd);

	printf("Inserire nome dello spettacolo: ");
	scanf("%s", nome_spettacolo);

	printf("Inserire il numero di spettacoli da trovare: ");
	scanf("%d", &n_spettacoli);

	while (n_spettacoli != 0)
	{
		if (pipe(p1p2) < 0)
		{
			perror("P0: errore pipe p1p2");
			exit(3);
		}

		if ((pid1 = fork()) < 0)
		{
			perror("P0: errore fork P1");
			exit(4);
		}

		if (pid1 == 0)
		{
			// codice P1
			signal(SIGINT, ctrlHandler);

			close(p1p2[0]);

			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);

			execlp("grep", "grep", nome_spettacolo, filepath, (char *)0);
			perror("P1: errore grep");
			exit(6);
		}

		if (pipe(p2p3) < 0)
		{
			perror("P0: errore pipe p2p3");
			exit(7);
		}

		if ((pid2 = fork()) < 0)
		{
			perror("P0: errore fork P2");
			exit(8);
		}

		if (pid2 == 0)
		{
			// codice P2
			signal(SIGINT, ctrlHandler);

			close(p1p2[1]);
			close(p2p3[0]);

			close(0);
			dup(p1p2[0]);
			close(p1p2[0]);

			close(1);
			dup(p2p3[1]);
			close(p2p3[1]);

			execlp("sort", "sort", "-n", (char *)0);
			perror("P2: errore sort");
			exit(9);
		}

		if (pipe(p3p0) < 0)
		{
			perror("P0: errore pipe p3p0");
			exit(10);
		}

		if ((pid3 = fork()) < 0)
		{
			perror("P0: errore fork P3");
			exit(11);
		}

		if (pid3 == 0)
		{
			// codice P3
			char n_spett[DIM];
			signal(SIGINT, ctrlHandler);

			sprintf(n_spett, "%d", n_spettacoli);

			close(p1p2[0]);
			close(p1p2[1]);
			close(p2p3[1]);
			close(p3p0[0]);

			close(0);
			dup(p2p3[0]);
			close(p2p3[0]);

			close(1);
			dup(p3p0[1]);
			close(p3p0[1]);

			execlp("head", "head", "-n", n_spett, (char *)0);
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

		printf("Spettacoli più imminenti: %s\n", ris);

		numero_richieste++;

		printf("Inserire nome dello spettacolo: ");
		scanf("%s", nome_spettacolo);

		printf("Inserire il numero di spettacoli da trovare: ");
		scanf("%d", &n_spettacoli);
	}

	printf("Numero di richieste eseguite: %d\n", numero_richieste);
	return 0;
}
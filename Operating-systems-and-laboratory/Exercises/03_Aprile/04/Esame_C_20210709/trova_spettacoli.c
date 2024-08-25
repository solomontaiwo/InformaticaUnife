#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

#define ROOT_PATH "/home/utente"
#define DIM 100
#define DIM_PATH 256
#define DIM_RIS 256

static volatile sig_atomic_t numero_richieste = 0;

void handler()
{
	printf("Numero di richieste servite: %d\n", numero_richieste);
	exit(0);
}

int main(int argc, char **argv)
{
	int fd, status, pid1, pid2, pid3, p1p2[2], p2p3[2], p3p0[2], n_spettacoli, nread;
	char filepath[DIM_PATH], nome_spettacolo[DIM], ris[DIM_RIS];

	if (argc != 2)
	{
		fprintf(stderr, "Errore: uso %s <nomeTeatro>.\n", argv[0]);
		exit(1);
	}

	if (argv[1][0] == '/')
	{
		fprintf(stderr, "Errore: <nomeTeatro> deve essere una stringa.\n");
		exit(2);
	}

	signal(SIGINT, handler);

	sprintf(filepath, "%s/%s.txt", ROOT_PATH, argv[1]);

	if ((fd = open(filepath, O_RDONLY)) < 0)
	{
		fprintf(stderr, "Errore: %s non è apribile in lettura.\n", filepath);
		exit(3);
	}
	close(fd);

	while (1)
	{
		printf("Inserisci il nome dello spettacolo: ");
		scanf("%s", nome_spettacolo);

		printf("Inserisci il numero di spettacoli da trovare: ");
		scanf("%d", &n_spettacoli);

		if (n_spettacoli == 0)
		{
			break;
		}
		else if (n_spettacoli < 0)
		{
			printf("Warning: <n> intero negativo\n");
			continue;
		}

		if ((pid1 = fork()) < 0)
		{
			perror("P0: errore fork P1");
			exit(4);
		}

		if ((pipe(p1p2)) < 0)
		{
			perror("P0: errore creazione pipe p1p2");
			exit(5);
		}

		if ((pipe(p2p3)) < 0)
		{
			perror("P0: errore creazione pipe p2p3");
			exit(6);
		}

		if ((pipe(p3p0)) < 0)
		{
			perror("P0: errore creazione pipe p3p0");
			exit(7);
		}

		if (pid1 == 0)
		{
			// Codice P1
			signal(SIGINT, SIG_DFL);
			close(p1p2[0]);

			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);

			execlp("grep", "grep", nome_spettacolo, filepath, (char *)0);
			perror("P1: errore grep");
			exit(8);
		}

		if ((pid2 = fork()) < 0)
		{
			perror("P0: errore creazione P2");
			exit(9);
		}

		if (pid2 == 0)
		{
			// Codice P2
			signal(SIGINT, SIG_DFL);
			close(p1p2[1]);
			close(p2p3[0]);

			close(0);
			dup(p1p2[0]);
			close(p1p2[0]);

			close(p2p3[1]);
			dup(p2p3[1]);
			close(p2p3[1]);

			execlp("sort", "sort", "-n", (char *)0);
			perror("P2: errore sort");
			exit(10);
		}

		if ((pid3 = fork()) < 0)
		{
			perror("P0: errore creazione P3");
			exit(11);
		}

		if (pid3 == 0)
		{
			// Codice P3
			signal(SIGINT, SIG_DFL);
			char n_str[DIM];
			sprintf(n_str, "%d", n_spettacoli);

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

			execlp("head", "head", "-n", n_str, (char *)0);
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
			perror("P0: errore nread");
			exit(13);
		}

		close(p3p0[0]);

		ris[nread] = '\0';
		printf("%s\n", ris);

		numero_richieste++;
	}

	printf("numero di richieste servite: %d\n", numero_richieste);
	return 0;
}
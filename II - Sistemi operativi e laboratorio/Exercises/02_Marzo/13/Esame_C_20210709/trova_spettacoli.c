// interfaccia: trova_spettacoli nomeTeatro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

#define DIM 256
#define ROOT_PATH "/home/utente"

static volatile sig_atomic_t numero_richieste = 0;

void handler()
{
	printf("Numero richieste elaborate: %d", numero_richieste);
	exit(0);
}

int main(int argc, char **argv)
{
	int fd, pid, status, N_spettacoli, p1p2[2], p2p3[2], p3p0[2], nread;
	char filepath[DIM], nome_spettacolo[DIM], ris[DIM];

	if (argc != 2)
	{
		fprintf(stderr, "Errore numero argomenti. Uso %s <nomeTeatro>", argv[0]);
		exit(1);
	}

	sprintf(filepath, "%s/%s.txt", ROOT_PATH, argv[1]);
	if ((fd = open(filepath, O_RDONLY)) < 0)
	{
		perror("Errore apertura file");
		exit(2);
	}
	close(fd);

	signal(SIGINT, handler);

	while (1)
	{
		printf("Inserisci il nome dello spettacolo: ");
		scanf("%s", nome_spettacolo);

		printf("Inserisci il numero di spettacoli: ");
		scanf("%d", &N_spettacoli);

		if (N_spettacoli == 0)
		{
			break;
		}
		else if (N_spettacoli < 0)
		{
			printf("Warning: <n> intero negativo\n");
			continue;
		}

		if (pipe(p1p2) < 0)
		{
			perror("P0: errore pipe p1p2");
			exit(3);
		}

		if ((pid = fork()) < 0)
		{
			perror("P0: errore fork P1");
			exit(4);
		}

		if (pid == 0)
		{
			// codice P1
			signal(SIGINT, SIG_DFL);

			close(p1p2[0]);

			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);

			execlp("grep", "grep", nome_spettacolo, filepath, (char *)0);
			perror("Errore exec grep P1");
			exit(5);
		}

		if ((pipe(p2p3)) < 0)
		{
			perror("P0: errore pipe p2p3");
			exit(6);
		}

		if ((pid = fork()) < 0)
		{
			perror("P0: errore fork P2");
			exit(7);
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
			perror("Errore exec sort");
			exit(8);
		}

		if ((pipe(p3p0)) < 0)
		{
			perror("P0: errore pipe p3p0");
			exit(9);
		}

		if ((pid = fork()) < 0)
		{
			perror("P0: errore fork P3");
			exit(11);
		}

		if (pid == 0)
		{
			// codice P3
			char str_n[4];

			signal(SIGINT, SIG_DFL);

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

			sprintf(str_n, "%d", N_spettacoli);
			execlp("head", "head", "-n", str_n, (char *)0);
			perror("P3: errore exec head");
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

		nread = (p3p0[0], ris, sizeof(ris) - 1);
		if (nread < 0)
		{
			perror("P0: errore read");
			exit(13);
		}

		close(p3p0[0]);

		ris[nread] = '\0';
		printf("%s\n", ris);

		numero_richieste++;
	}

	printf("Numero richieste elaborate: %d", numero_richieste);
	return 0;
}
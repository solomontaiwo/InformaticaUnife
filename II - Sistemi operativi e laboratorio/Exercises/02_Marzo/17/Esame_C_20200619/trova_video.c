// interfaccia trova_video dir
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define DIM 50

static volatile sig_atomic_t richieste = 0;

void handler()
{
	printf("Numero di richieste eseguite: %d\n", richieste);
	exit(0);
}

int main(int argc, char **argv)
{
	int fd, status, pid, p1p2[2];
	char tipo_video[DIM], data[DIM], to_open[DIM];

	if (argc != 2)
	{
		fprintf(stderr, "Errore argomenti: uso %s <dir>\n", argv[0]);
		exit(1);
	}

	if (argv[1][0] == '/')
	{
		fprint(stderr, "Errore: <dir> deve essere un percorso relativo\n");
		exit(2);
	}

	signal(SIGINT, handler);

	if ((fd = open(argv[1], O_DIRECTORY)) < 0)
	{
		fprintf(stderr, "Errore, %s non è una directory\n", argv[1]);
		exit(3);
	}
	close(fd);

	while (1)
	{
		printf("Inserisci il tipo di video: ");
		scanf("%s", tipo_video);

		printf("Inserisci la data di interesse (YYYYMM): ");
		scanf("%s", data);
		if ((pipe(p1p2)) < 0)
		{
			fprintf(stderr, "Errore pipe p1p2\n");
			exit(4);
		}

		sprintf(to_open, "%s/%s.txt", argv[1], data);

		if ((fd = open(to_open, O_RDONLY)) < 0)
		{
			fprintf(stderr, "Impossibile aprire %s.txt", data);
			exit(5);
		}
		close(fd);

		if ((pid = fork()) < 0)
		{
			perror("P0: errore fork P1");
			exit(6);
		}

		if (pid == 0)
		{
			// codice P1
			close(p1p2[0]);

			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);

			execlp("grep", "grep", tipo_video, to_open, (char *)0);
			perror("P1: errore grep");
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
			close(p1p2[1]);

			close(0);
			dup(p1p2[0]);
			close(p1p2[0]);

			execlp("sort", "sort", "-r", (char *)0);
			perror("P2: errore sort");
			exit(9);
		}

		close(p1p2[0]);
		close(p1p2[1]);

		wait(&status);
		wait(&status);

		richieste++;
	}

	printf("Numero di richieste eseguite: %d\n", richieste);
	return 0;
}
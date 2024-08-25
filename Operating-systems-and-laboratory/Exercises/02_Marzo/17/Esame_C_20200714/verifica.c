// interfaccia: verifica fileBollette
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#define DIM 50

static volatile sig_atomic_t numero_richieste = 0;

void handler()
{
	printf("Numero richiese eseguite: %d\n", numero_richieste);
	exit(0);
}

int main(int argc, char **argv)
{
	int pid1, pid2, pid3, fd, status, p1p2[2], p2p3[2];
	char tipologia[DIM];

	if (argc != 2)
	{
		fprintf(stderr, "Errore: uso %s <fileBollette>\n");
		exit(1);
	}

	if (argv[1][0] != '/')
	{
		fprintf(stderr, "Errore: <fileBollette> non è un percorso assoluto\n");
		exit(2);
	}

	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		fprint("Errore lettura %s\n", argv[1]);
		exit(3);
	}
	close(fd);

	signal(SIGINT, handler);

	printf("Che tipo di bolletta vuoi controllare?");
	scanf("%s", tipologia);

	while (strcmp(tipologia, "esci") != 0)
	{
		signal(SIGINT, SIG_DFL);
		pid1 = fork();

		pipe(p1p2);

		if (p1p2 < 0)
		{
			perror("P0: pipe p1p2");
		}

		if (pid1 < 0)
		{
			perror("P0: errore fork");
			exit(4);
		}

		if (pid1 == 0)
		{
			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);
			close(p1p2[0]);

			execlp("grep", "grep", tipologia, argv[1]);
			perror("P1;: errore grep");
			exit(5);
		}

		close(p1p2[1]);

		if (pipe(p2p3) < 0)
		{
			perror("P0: errore pipe p2p3");
			exit(6);
		}

		if ((pid2 = fork()) < 0)
		{
			perror("P0: errore fork P2");
			exit(7);
		}

		if (pid2 == 0)
		{
			close(0);
			dup(p1p2[0]);
			close(p1p2[0]);

			close(1);
			dup(p2p3[1]);
			close(p2p3[0]);
			close(p2p3[1]);

			excelp("grep", "grep", "da pagare", (char *)0);
			perror("P1: errore grep");
			exit(8);
		}

		close(p1p2[0]);
		close(p2p3[1]);

		if ((pid3 = fork()) < 0)
		{
			perror("P0: errore fork pid3");
			exit(9);
		}

		if (pid3 == 0)
		{
			close(0);
			dup(p2p3[0]);
			close(p2p3[0]);

			execlp("sort", "sort", "-n", "-r", (char *)0);
			perror("P3: errore sort");
			exit(10);
		}

		close(p2p3[0]);

		wait(&status);
		wait(&status);
		wait(&status);

		numero_richieste++;

		printf("Che tipo di bolletta vuoi controllare?");
		scanf("%s", tipologia);
	}
	printf("Fine applicazione. Numero richieste totali: %d\n", numero_richieste);
	return 0;
}
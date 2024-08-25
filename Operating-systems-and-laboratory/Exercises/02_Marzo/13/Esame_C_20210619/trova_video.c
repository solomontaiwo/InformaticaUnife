// interfaccia: trova_video dir
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define DIM 256

static volatile sig_atomic_t richieste_servite = 0;

void handler()
{
	printf("Numero richieste servite: %d\n", richieste_servite);
	exit(0);
}

int main(int argc, char **argv)
{
	int status, pid, fd, p0p1[2];
	char tipo_video[DIM], data[9], to_open[DIM];

	if (argc != 2)
	{
		fprintf(stderr, "Errore nell'uso");
		exit(1);
	}

	if (argv[1][0] == '/')
	{
		fprintf(stderr, "Errore: dir deve essere un nome relativo di directory");
		exit(2);
	}

	if ((fd = open(argv[1], O_DIRECTORY)) < 0)
	{
		perror("Errore nell'apertura di dir");
		exit(2);
	}
	close(fd);

	signal(SIGINT, handler);

	while (1)
	{
		printf("Inserire tipo video:\n");
		scanf("%s", tipo_video);
		printf("Inserire data in formato YYYYMM:\n");
		scanf("%s", data);

		sprintf(to_open, "%s/%s.txt", argv[1], data);

		if ((fd = open(to_open, O_RDONLY)) < 0)
		{
			perror("Errore nell'apertura del file");
			exit(3);
		}
		close(fd);

		if (pipe(p0p1) < 0)
		{
			perror("Errore pipe");
			exit(4);
		}

		pid = fork();

		if (pid < 0)
		{
			perror("P0: errore fork P1");
			exit(5);
		}

		if (pid == 0)
		{
			// codice P1
			close(p0p1[0]);

			close(1);
			dup(p0p1[1]);
			close(p0p1[1]);

			execlp("grep", "grep", tipo_video, to_open, (char *)0);
			perror("Errore grep P1");
			exit(6);
		}

		pid = fork();

		if (pid < 0)
		{
			perror("P0: errore fork P2");
			exit(7);
		}

		if (pid == 0)
		{
			// codice P2
			close(p0p1[1]);

			close(0);
			dup(p0p1[0]);
			close(p0p1[0]);

			execlp("sort", "sort", "-r", "-n", (char *)0);
			perror("Errore sort");
			exit(8);
		}

		close(p0p1[0]);
		close(p0p1[1]);
		wait(&status);
		wait(&status);
		richieste_servite++;
	}
	return 0;
}
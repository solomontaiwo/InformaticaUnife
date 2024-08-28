// interfaccia: test_eseguiti dir data
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define DIM 100

static volatile sig_atomic_t count = 0;

void handler()
{
	printf("Numero di byte ricevuti: %d\n", count);
	exit(0);
}

int main(int argc, char **argv)
{
	int fd, status, nread, nwrite;
	int p0p1[2], p0p2[2], pid;
	char filepath[DIM], res[DIM], ref[DIM];

	if (argc != 3)
	{
		printf("Errore uso: %s <dir> <data>\n", argv[0]);
		exit(1);
	}

	if (argv[1][0] == '/')
	{
		printf("Errore: <dir> deve essere un path relativo\n");
		exit(2);
	}

	fd = open(argv[1], O_DIRECTORY);

	if (fd < 0)
	{
		perror("P0: errore open directory");
		exit(3);
	}
	close(fd);

	sprintf(filepath, "%s/%s.txt", filepath, argv[1]),

		fd = open(filepath, O_RDONLY);

	if (fd < 0)
	{
		fprintf(stderr, "P0: impossibile leggere file %s", argv[1]);
		exit(4);
	}
	close(fd);

	signal(SIGINT, handler);

	if (pipe(p0p1) < 0)
	{
		perror("P0: pipe p0p1");
		exit(5);
	}

	if (pipe(p0p2) < 0)
	{
		perror("P0: pipe p0p2");
		exit(6);
	}

	if ((pid = fork()) < 0)
	{
		perror("P0: errore fork P1");
		exit(7);
	}

	if (pid == 0)
	{
		close(p0p1[1]);
		close(p0p2[0]);

		signal(SIGINT, SIG_DFL);

		while (1)
		{
			nread = read(p0p1[0], ref, sizeof(ref) - 1);
			if (nread < 0)
			{
				perror("P1: read");
				exit(8);
			}

			ref[nread] = '\0';

			pid = fork();

			if ((pid = fork()) < 0)
			{
				perror("P1: errore fork P2");
				exit(9);
			}

			if (pid == 0)
			{
				signal(SIGINT, SIG_DFL);

				close(p0p1[0]);

				close(1);
				dup(p0p2[1]);
				close(p0p2[1]);

				execlp("grep", "grep", ref, filepath, (char *)0);
				perror("P1: errore grep");
				exit(10);
			}

			wait(&status);
		}
	}

	close(p0p1[0]);
	close(p0p2[1]);

	while (1)
	{
		printf("Inserire refertatore\n");
		scanf("%s", ref);

		nwrite = write(p0p1[1], ref, strlen(ref) + 1);
		if (nwrite != (int)(strlen(ref) + 1))
		{
			perror("P0: write");
			exit(11);
		}

		nread = read(p0p2[0], res, sizeof(res) - 1);
		if (nread < 0)
		{
			perror("P0: read");
			exit(12);
		}

		res[nread] = '\0';
		printf("%s\n", res);

		count = count + nread;
	}
	return 0;
}
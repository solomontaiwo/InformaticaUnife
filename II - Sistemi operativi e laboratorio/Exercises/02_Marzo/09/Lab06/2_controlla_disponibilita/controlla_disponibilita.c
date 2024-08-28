// interfaccia: controlla_disponibilita magazzino-1 magazzino-2 ... magazzino-N
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

#define SEARCH_STR 100
#define ANS_STR 20

int main(int argc, char **argv)
{
    typedef int pipe_t[2];

    int i, j, n_ret, pid, status;
    char nome[SEARCH_STR], ret[ANS_STR];

    pipe_t *pipes_in, *pipes_out;

    if (argc < 2)
    {
        fprintf(stderr, "Uso: %s <magazzino-1> ... <magazzino-N\n", argv[0]);
        exit(1);
    }

    for (i = 1; i < argc; i++)
    {
        if (argv[i][0] == '/')
        {
            fprintf(stderr, "%s non è un path relativo\n", argv[i]);
            exit(2);
        }
    }

    pipes_in = (pipe_t *)malloc((argc - 1) * sizeof(pipe_t));
    pipes_out = (pipe_t *)malloc((argc - 1) * sizeof(pipe_t));

    for (i = 0; i < (argc - 1); i++)
    {
        if (pipe(pipes_in[i]) < 0)
        {
            perror("pipes_in");
            exit(3);
        }
        if (pipe(pipes_out[i]) < 0)
        {
            perror("pipes_out");
            exit(4);
        }
        if (pid == 0)
        {
            for (j = 0; j <= i; j++)
            {
                close(pipes_in[j][1]);
                close(pipes_out[j][0]);
            }

            while (read(pipes_in[i][0], nome, sizeof(nome)) > 0)
            {
                if ((pid = fork() < 0))
                {
                    perror("fork figlio");
                    exit(5);
                }
                if (pid == 0)
                {
                    close(pipes_in[i][0]);

                    close(1);
                    dup(pipes_out[i][1]);
                    close(pipes_out[i][1]);

                    execlp("grep", "grep", "-c", nome, argv[i + 1], (char *)0);
                    perror("exec nipote");
                    exit(6);
                }
                wait(&status);
            }

            close(pipes_in[i][0]);
            close(pipes_out[i][1]);
            exit(0);
        }

        close(pipes_in[i][0]);
        close(pipes_out[i][1]);
    }

    printf("\nInserisci il nome dell'oggetto da cercare:\n");
    scanf("%s", nome);

    while (strcmp(nome, "fine"))
    {
        for (i = 0; i < (argc - 1); i++)
        {
            if (write(pipes_in[i][1], nome, strlen(nome) + 1) < 0)
            {
                perror("write");
                exit(7);
            }
        }

        for (i = 0; i < (argc - 1); i++)
        {
            memset(ret, 0, sizeof(ret));
            if ((n_ret = read(pipes_out[i][0], ret, sizeof(ret))) < 0)
            {
                perror("read");
                exit(7);
            }
            printf("Nel file %s ci sono %d unità di stoccaggio per la materia prima %s\n", argv[i + 1], atoi(ret), nome);
            scanf("%s", nome);
        }

        for (i = 0; i < (argc - 1); i++)
        {
            close(pipes_in[i][1]);
            close(pipes_out[i][0]);
            wait(&status);
        }

        free(pipes_in);
        free(pipes_out);

        return 0;
    }
}
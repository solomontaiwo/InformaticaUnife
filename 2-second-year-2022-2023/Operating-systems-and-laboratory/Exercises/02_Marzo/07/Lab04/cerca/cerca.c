#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd, pid, status, i;
    char stringa[256];

    if (argc < 3)
    {
        fprintf(stderr, "Errore numero argomenti. Uso %s <nomefile> <stringa1> ... <stringaN>", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (fd < 0)
    {
        fprintf(stderr, "Errore nella creazione del file %s\n", argv[1]);
        exit(2);
    }

    close(fd);

    for (i = 2; i < argc; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("Errore fork\n");
            exit(3);
        }
        else if (pid == 0)
        {
            char log[256];

            fd = open(argv[1], O_WRONLY | O_APPEND);

            sprintf(log, "%s %s\n", argv[1], argv[i]);

            write(fd, log, strlen(log));

            close(fd);

            printf("\nNumero volte che si ripete la stringa %s:\n", argv[i]);

            execlp("grep", "grep", "-c", argv[i], argv[1], (char *)0);

            perror("Errore exec");
            exit(4);
        }
        else
        {
            wait(&status);
        }
    }
    return 0;
}
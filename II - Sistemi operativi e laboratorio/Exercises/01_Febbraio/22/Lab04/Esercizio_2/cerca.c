#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{

    int pid, fd, status, i;

    if (argc < 3)
    {
        fprintf(stderr, "Uso: ./cerca <nomefile> <stringa1> ... <stringaN> \n");
        exit(1);
    }

    fd = open("conteggio.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd < 0)
    {
        perror("Errore nella creazione del file di conteggio, termino\n");
        exit(2);
    }
    close(fd);

    for (i = 2; i < argc; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("fork");
            exit(3);
        }
        else if (pid == 0)
        {
            char log[256];

            fd = open("conteggio.txt", O_WRONLY | O_APPEND);

            sprintf(log, "%s %s\n", argv[1], argv[i]);
            write(fd, log, strlen(log));

            close(fd);

            printf("\nNum volte che si ripete la stringa %s:\n", argv[i]);
            execlp("grep", "grep", "-c", argv[i], argv[1], (char *)0);

            perror("exec");
            exit(4);
        }
        else
        {
            wait(&status);
        }
    }

    return 0;
}

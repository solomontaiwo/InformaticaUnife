#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int pid, fd, status, i;

    if (argc < 3)
    {
        fprintf(stderr, "Errore: uso %s <nomefile> <stringa1> ... <stringaN>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd < 0)
    {
        perror("Errore nella creazione del file di conteggio, termino\n");
        exit(2);
    }
    close(fd);

    for (i = 2; i < argc; i++)
    {
        if ((pid = fork()) < 0)
        {
            // Errore
            perror("Errore fork");
            exit(3);
        }
        else if (pid == 0)
        {
            // Figlio
            char log[256];

            // apro il file conteggio.txt in append
            fd = open(argv[1], O_WRONLY | O_APPEND);

            // creo il file log dell'operazione di conteggio
            sprintf(log, "%s %s", argv[1], argv[i]);

            // scrivo il log su file
            write(fd, log, strlen(log));

            close(fd);

            printf("\nNumero di volte che si ripete la stringa %s: \n", argv[i]);

            // chiamata a: grep -c stringa nomefile. Esecuzione senza ritorno
            execlp("grep", "grep", "-c", argv[i], argv[1], (char *)0);

            // se execlp non va a buon fine
            perror("Errore exec");
            exit(4);
        }
        else
        {
            // padre, che attende la terminazione del figlio
            wait(&status);
        }
    }

    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define DIM 50

int main(int argc, char **argv)
{
    int pid, status, fd, num;
    char nome[DIM];

    if (argc != 2)
    {
        printf("Uso: ./anteprima <num>\n");
        exit(1);
    }

    if ((num = atoi(argv[1])) <= 0)
    {
        printf("Errore: %s deve essere un numero intero positivo maggiore di zero\n", argv[1]);
        exit(2);
    }

    printf("Inserisci il nome del file di cui visualizzare l'anteprima ('fine' per uscire): ");
    scanf("%s", nome);

    while (strcmp(nome, "fine") != 0)
    {
        if ((fd = open(nome, O_RDONLY)) < 0)
        {
            if (errno == ENOENT)
            {
                printf("Il file %s non esiste\n", nome);
            }
            else
            {

                perror("open");
                exit(3);
            }
        }
        else
        {

            close(fd);

            pid = fork();
            if (pid < 0)
            {
                perror("fork");
                exit(4);
            }
            else if (pid == 0)
            {

                printf("\nAnteprima del file %s:\n", nome);
                execlp("head", "head", "-n", argv[1], nome, (char *)0);

                perror("exec");
                exit(5);
            }

            wait(&status);
        }

        printf("\nInserisci il nome del file di cui visualizzare "
               "l'anteprima (\"fine\" per uscire): ");
        scanf("%s", nome);
    }

    return 0;
}
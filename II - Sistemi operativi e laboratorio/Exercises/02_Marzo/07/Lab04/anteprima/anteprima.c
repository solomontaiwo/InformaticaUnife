#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define DIM 50

int main(int argc, char **argv)
{
    int fd, pid, status, num;
    char nome_file[DIM];

    if (argc != 2)
    {
        fprintf(stderr, "Errore argomenti. Uso %s <num>\n", argv[0]);
        exit(1);
    }

    if ((num = atoi(argv[1])) <= 0)
    {
        printf("Errore: %s deve essere un intero positivo maggiore di zero\n", argv[1]);
        exit(2);
    }

    printf("Inserisci il nome del file di cui vuoi visualizzare l'anteprima (\"fine\") per uscire): ");
    scanf("%s", nome_file);

    while (strcmp(nome_file, "fine") != 0)
    {
        if ((fd = open(nome_file, O_RDONLY)) < 0)
        {
            if (errno == ENOENT)
            {
                printf("Il file %s non esiste\n", nome_file);
            }
            else
            {
                perror("Errore open");
                exit(3);
            }
        }
        else
        {
            close(fd);
        }

        if ((pid = fork()) < 0)
        {
            perror("Errore nella fork");
            exit(4);
        }
        else if (pid == 0)
        {
            printf("\nAnteprima del file %s:\n", nome_file);
            execlp("head", "head", "-n", argv[1], nome_file, (char *)0);
            perror("Errore nell'exec");
            exit(5);
        }

        wait(&status);

        printf("\nInserisci il nome del file di cui visualizzare l'anteprima (\"fine\") per uscire): ");
        scanf("%s", nome_file);
    }
    return 0;
}
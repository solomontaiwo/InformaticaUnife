#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd;
    char string[1024];

    if (argc < 2)
    {
        fprintf(stderr, "Errore: uso %s <stringa>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);

    if (fd < 0)
    {
        fprintf(stderr, "Errore creazione file %s\n", argv[1]);
        exit(2);
    }

    printf("Inserisci una stringa: \n");
    fgets(string, 1024, stdin);

    while (strcmp(string, "fine\n") != 0)
    {
        write(fd, string, strlen(string));
        printf("Inserisci un'altra stringa ('fine' per terminare):\n");
        fgets(string, 1024, stdin);
    }

    close(fd);

    return 0;
}
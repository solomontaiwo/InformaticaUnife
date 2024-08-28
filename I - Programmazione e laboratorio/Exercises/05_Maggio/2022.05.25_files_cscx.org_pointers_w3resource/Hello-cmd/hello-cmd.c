#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char nome[20];

    if (argc != 2)
    {
        printf("Errore: argomento mancante.\n");
        exit(1);
    }

    strcpy(nome, argv[1]);

    printf("Hello, %s.\n");

    return 0;
}
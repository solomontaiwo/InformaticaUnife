#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int main(int argc, char *argv[])
{
    FILE *pft;
    char stringa[SIZE], lettera;

    if (argc != 2)
    {
        printf("Errore, riprova ad avviare il programma con un argomento valido.\n");
        exit(1);
    }

    if ((pft = fopen(argv[1], "rt")) == NULL)
    {
        printf("Impossibile aprile il file di testo.\n");
        exit(2);
    }
    while ((lettera = fgetc(pft)) != EOF)
    {
        printf("%c", lettera);
    }

    return 0;
}
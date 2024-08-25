#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    char nome;

    if (argc != 2)
    {
        printf("Errore nell'argomento. Immettere il nome di un file di testo.\n");
        exit(1);
    }

    //   printf("Argomento inserito correttamente.\n");

    if ((pft = fopen(argv[1], "rt")) == NULL)
    {
        printf("Impossibile aprire il file.\n");
        exit(2);
    }

    // else printf("File aperto correttamente!\n");

    while ((nome = fgetc(pft)) != EOF)
        printf("%c", nome);

    puts("");

    fclose(pft);
}
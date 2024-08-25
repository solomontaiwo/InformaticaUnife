#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *pft;

    struct rubrica
    {
        char nome[20];
        char indirizzo[30];
        char numero[20];
    } * contatto;

    char nomeDaCercare[20];

    if ((pft = fopen("rubrica.txt", "rt")) == NULL)
    {
        printf("Impossibile leggere il file di testo.\n");
        exit(2);
    }

    scanf("%s", nomeDaCercare);

    while (!feof(pft))
    {
        fscanf(pft, "%s %s %s", contatto->nome, contatto->indirizzo, &contatto->numero);
        if ((strcmp(nomeDaCercare, contatto->nome)) == 0)
        {
            printf("%s %s %s\n", contatto->nome, contatto->indirizzo, contatto->numero);
            break;
        }
    }

    fclose(pft);
    return 0;
}
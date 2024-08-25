// Si scriva su un file di testo di nome prova.txt quello che l’utente inserisce da tastiera parola per parola, finché non inserisce la parola "FINE". //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

int main(void)
{
    FILE *fp;

    char parola[SIZE];

    fp = fopen("prova.txt", "wt");
    if (fp == NULL)
    {
        printf("Non e' stato possibile aprire il file.\n");
        exit(1);
    }
    else
        do
        {
            scanf("%s", parola);
            if (strcmp(parola, "FINE") != 0)
                fprintf(fp, "%s\n", parola);
        } while (strcmp(parola, "FINE") != 0);

    if (fclose(fp) != 0)
    {
        printf("Errore nella chiusura del file.\n");
        exit(2);
    }
    return 0;
}
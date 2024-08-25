#include <stdio.h>

FILE *accessiPtr;

int main(void)
{
    if ((accessiPtr = fopen("Dati soci palestra.txt", "r")) == NULL)
        puts("Non sono riuscito a trovare il file da aprire.");
    else
    {
        puts("Ti leggero' e ti mostrero' i dati contenuti all'interno del file di testo 'Dati soci palestra'.");
        puts("");

        unsigned int numeroTessera;
        char nome[20];

        unsigned int giorno, mese, anno;

        float costoIscrizione;

        printf("%-17s%-14s%-10s%19s\n", "Numero Tessera", "Nome utente", "Data iscrizione", "Costo iscrizione");

        fscanf(accessiPtr, "%d %s %d/%d/%d %f", &numeroTessera, nome, &giorno, &mese, &anno, &costoIscrizione);

        while (!feof(accessiPtr))
        {
            printf("%-17d%-14s%d/%d/%-13d%.2f \n", numeroTessera, nome, giorno, mese, anno, costoIscrizione);
            fscanf(accessiPtr, "%d %s %d/%d/%d %f", &numeroTessera, nome, &giorno, &mese, &anno, &costoIscrizione);
        }
    }
    puts("");
    fclose(accessiPtr);
}
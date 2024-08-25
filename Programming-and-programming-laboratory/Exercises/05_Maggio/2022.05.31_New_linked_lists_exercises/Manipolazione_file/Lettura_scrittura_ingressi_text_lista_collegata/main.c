#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scritturaNomi.h"

int main(int argc, char *argv[])
{
    FILE *pft;
    char nomeFile[30];
    int nominativi;

    printf("Inserisci il nome del file di testo (estensione .txt, senza spazi): ");
    scanf("%29s", nomeFile);

    if ((pft = fopen(nomeFile, "wt")) == NULL)
    {
        printf("Impossibile creare il file di testo %s\n", nomeFile);
        exit(1);
    }

    Lista persone;

    inizializzaLista(&persone);

    printf("Inserisci il numero di persone (\"FINE\" per uscire): ");
    scanf("%d", &nominativi);

    while (nominativi != 0)
    {
        insCoda(&persone, nominativi);
        fprintf(pft, "%d ", nominativi);
        printf("Inserisci il numero di persone (\"FINE\" per uscire): ");
        scanf("%d", &nominativi);
    }

    stampa(persone);

    fclose(pft);

    return 0;
}
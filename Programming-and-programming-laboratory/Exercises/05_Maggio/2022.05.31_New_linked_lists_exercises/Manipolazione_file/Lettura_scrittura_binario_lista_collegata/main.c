#include <stdio.h>
#include <stdlib.h>

#include "scritturaBinario.h"

int main(int argc, char *argv[])
{
    char nomeFile[30];
    FILE *pfb;
    int numeroInserito;

    printf("Inserisci il nome del file: ");
    scanf("%[^\n]", nomeFile);

    if ((pfb = fopen(nomeFile, "wb")) == NULL)
    {
        printf("Impossibile creare il file %s\n", nomeFile);
        exit(1);
    }

    Lista nuovaLista1;

    creaLista(&nuovaLista1);

    while (numeroInserito != 0)
    {
        scanf("%d", &numeroInserito);
        insTesta(&nuovaLista1, numeroInserito);
    }

    printf("\nOrdinamento lista collegata...\n");
    ordina(&nuovaLista1);

    printf("Numeri ordinati: ");
    stampa(nuovaLista1);

    printf("\nInserimento lista in file binario...\n");
    while (nuovaLista1)
    {
        fprintf(pfb, "%d ", nuovaLista1->d);
        nuovaLista1 = nuovaLista1->next;
    }

    fclose(pfb);

    return 0;
}
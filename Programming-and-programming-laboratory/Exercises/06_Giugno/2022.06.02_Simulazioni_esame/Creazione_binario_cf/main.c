#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funzioniCreazioneBinarioCF.h"

int main(int argc, char *argv[])
{
    Persona a;
    Lista l;
    FILE *pfb;

    if (argc != 2)
    {
        printf("Errore, immettere come argomento il nome del file che si vuole creare.\n");
        exit(1);
    }

    if ((pfb = fopen(argv[1], "wb")) == NULL)
    {
        printf("Impossibile creare il file di testo %s.\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    printf("Inserisci i dati dell'utente:\n");

    while ((strcmp(a.nome, "FINE")) != 0)
    {
        printf("NOME - ");
        scanf("%s", a.nome);
        printf("ETA - ");
        scanf("%d", &a.eta);
        printf("CODICE FISCALE - ");
        scanf("%s", a.codiceFiscale);

        scriviSuFile(a.nome, a.eta, a.codiceFiscale, pfb);
        puts("");
    }

    fclose(pfb);

    return 0;
}
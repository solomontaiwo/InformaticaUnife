#include <stdio.h>
#include <stdlib.h>

#include "listaImmobili.h"

int main(int argc, char *argv[])
{
    Immobile a;
    Lista l;
    FILE *pfb;

    if (argc != 2)
    {
        printf("Errore, immettere come argomento il nome del file da leggere.\n");
        exit(1);
    }

    if ((pfb = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire il file %s in lettura.\n");
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&a, sizeof(Immobile), 1, pfb)) == 1)
    {
        aggiorna(&l, a);
    }

    fclose(pfb);
    stampa(l);

    return 0;
}
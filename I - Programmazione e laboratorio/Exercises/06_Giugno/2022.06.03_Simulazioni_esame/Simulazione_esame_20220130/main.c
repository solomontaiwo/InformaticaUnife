#include <stdio.h>
#include <stdlib.h>

#include "listaEsami.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore, immettere come argomento il nome del file.\n");
        exit(1);
    }

    FILE *pfb;

    if ((pfb = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire %s per lettura dati.\n", argv[1]);
        exit(2);
    }

    Risultato r;
    Dato d;
    Lista l;

    nuovaLista(&l);

    while ((fread(&r, sizeof(Risultato), 1, pfb)) == 1)
    {
        aggiorna(&l, r);
    }

    fclose(pfb);
    stampa(l);

    return 0;
}
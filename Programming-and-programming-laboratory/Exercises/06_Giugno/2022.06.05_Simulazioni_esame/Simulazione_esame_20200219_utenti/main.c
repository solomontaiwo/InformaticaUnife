#include <stdio.h>
#include <stdlib.h>

#include "listaUtenti.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore, argomento non valido.\n");
        exit(1);
    }

    FILE *pfb;
    Record r;
    Lista l;

    if ((pfb = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile leggere il file %s.\n", argv[1]);
        exit(1);
    }

    while ((fread(&r, sizeof(Record), 1, pfb)) == 1)
    {
        aggiorna(&l, r);
    }

    fclose(pfb);
    stampa(l);

    return 0;
}
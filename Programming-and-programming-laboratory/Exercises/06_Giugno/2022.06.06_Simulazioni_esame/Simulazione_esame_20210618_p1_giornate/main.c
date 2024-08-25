#include <stdio.h>
#include <stdlib.h>

#include "listaGiornate.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Record r;
    Lista l;

    if (argc != 2)
    {
        printf("Errore, argomento %s non valido.\n", argv[1]);
        exit(1);
    }

    f = fopen(argv[1], "rb");
    if (f == NULL)
    {
        printf("Impossibile leggere il file %s\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&r, sizeof(Record), 1, f)) == 1)
        aggiorna(&l, r);

    fclose(f);
    stampa(l);

    return 0;
}
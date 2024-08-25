#include <stdio.h>
#include <stdlib.h>

#include "listaPersone.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Record r;
    Lista l;

    if (argc != 2)
    {
        printf("Errore, argomento non valido.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire in lettura file binario %s\n", argv[1]);
        exit(1);
    }

    nuovaLista(&l);

    while ((fread(&r, sizeof(Record), 1, f)) == 1)
        aggiorna(&l, r);

    fclose(f);

    stampa(l);

    return 0;
}
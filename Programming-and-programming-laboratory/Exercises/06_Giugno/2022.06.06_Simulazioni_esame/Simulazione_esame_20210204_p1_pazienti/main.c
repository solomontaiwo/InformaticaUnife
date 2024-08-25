#include <stdio.h>
#include <stdlib.h>

#include "listaPazienti.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore, argomento non valido.\n");
        exit(1);
    }

    FILE *f;
    Record r;
    Lista l;

    f = (fopen(argv[1], "rb"));
    if (f == NULL)
    {
        printf("Impossibile leggere il file binario %s\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&r, sizeof(Record), 1, f)) == 1)
    {
        aggiorna(&l, r);
    }

    fclose(f);
    stampa(l);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "listaCani.h"

int main(int argc, char *argv[])
{
    FILE *pfb;
    Record r;
    Lista l;

    if (argc != 2)
    {
        printf("Errore, argomento deve essere nome file da aprire.\n");
        exit(1);
    }

    if ((pfb = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire file %s per lettura.\n");
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&r, sizeof(Record), 1, pfb)) == 1)
    {
        aggiorna(&l, r);
    }

    fclose(pfb);
    
    stampa(l);

    return 0;
}
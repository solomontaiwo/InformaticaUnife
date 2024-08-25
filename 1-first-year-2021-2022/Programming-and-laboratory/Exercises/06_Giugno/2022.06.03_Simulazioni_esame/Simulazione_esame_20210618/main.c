#include <stdio.h>
#include <stdlib.h>

#include "listaGiornate.h"

int main(int argc, char *argv[])
{
    FILE *pfb;
    Record r;
    Lista l;

    if (argc != 2)
    {
        printf("Errore, immettere come argomento nome di file da utilizzare.\n");
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
        // printf("%d/%d %.2f\n", r.giorno, r.mese, r.oreImpiegate);
        aggiorna(&l, r);
    }

    fclose(pfb);
    stampa(l);
    return 0;
}
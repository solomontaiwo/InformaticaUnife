#include <stdlib.h>
#include <stdio.h>

#include "listaImmobili.h"

int main(int argc, char *argv[])
{
    FILE *pfb;
    Immobile imm;

    if (argc != 2)
    {
        printf("Errore. Inserire come argomento il nome del file binario da cui leggere i dati.\n");
        exit(1);
    }

    if ((pfb = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire ilf file %s in lettura.\n", argv[1]);
        exit(2);
    }

    Lista immobili;
    inizializzaLista(&immobili);

    while (fread(&imm, sizeof(Immobile), 1, pfb) == 1)
        insOrd(&immobili, imm);

    stampa(immobili);

    fclose(pfb);

    return 0;
}
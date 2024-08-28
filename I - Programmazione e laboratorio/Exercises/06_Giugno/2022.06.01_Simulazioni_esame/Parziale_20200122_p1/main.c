#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaVeicoli.h"

int main(int argc, char *argv[])
{

    FILE *pfb;
    Lista v;
    Accesso a;

    if (argc != 2)
    {
        printf("Errore, immettere da analizzare come argomento il nome del file.\n");
        exit(1);
    }

    if ((pfb = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile leggere il file %s.\n", argv[1]);
        exit(2);
    }

    inizializzaLista(&v);

    while ((fread(&a, sizeof(Accesso), 1, pfb)) == 1)
    {
        aggiorna(&v, a.targa);
    }

    fclose(pfb);
    stampaImporti(v);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "listaEsami.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Risultato ris;
    Lista l;

    if (argc != 2)
    {
        printf("Errore, argomento non valido.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile leggere file binario %s in lettura.\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&ris, sizeof(Risultato), 1, f)) == 1)
        aggiorna(&l, ris);

    fclose(f);
    stampa(l);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "listaUrl.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Visita v;
    Lista l;

    if (argc != 2)
    {
        printf("Errore, argomento non valido.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire in lettura file binario %s\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&v, sizeof(Visita), 1, f)) == 1)
        aggiorna(&l, v);

    fclose(f);

    stampa(l);

    return 0;
}
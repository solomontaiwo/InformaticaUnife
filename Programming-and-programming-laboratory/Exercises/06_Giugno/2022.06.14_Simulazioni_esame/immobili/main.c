#include <stdio.h>
#include <stdlib.h>

#include "listaImmobili.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Immobile imm;
    Lista l;

    if (argc != 2)
    {
        printf("Errore, argomento non valido.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire file binario %s in lettura.\n");
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&imm, sizeof(Immobile), 1, f)) == 1)
        aggiorna(&l, imm);

    fclose(f);
    stampa(l);

    return 0;
}
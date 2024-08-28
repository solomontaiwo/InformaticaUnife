#include <stdio.h>
#include <stdlib.h>

#include "listaGiornate.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Registrazione r;
    Lista l;

    if (argc != 2)
    {
        printf("Errore argomento.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire file %s in lettura.\n", argv[1]);
        exit(2);
    }

    while ((fread(&r, sizeof(Registrazione), 1, f)) == 1)
        aggiornaLista(&l, r);

    fclose(f);

    stampa(l);

    return 0;
}
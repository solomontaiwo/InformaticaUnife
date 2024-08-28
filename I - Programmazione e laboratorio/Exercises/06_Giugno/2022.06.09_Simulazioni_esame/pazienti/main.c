#include <stdio.h>
#include <stdlib.h>

#include "listaPazienti.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Rilevazione r;
    Lista l;

    if (argc != 2)
    {
        printf("Errore, argomento non valido o assente.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("impossibile aprire file binario %s\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&r, sizeof(Rilevazione), 1, f)) == 1)
        aggiorna(&l, r);

    fclose(f);
    stampa(l);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "listaNazioni.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Nazione naz;
    Lista l;

    if (argc != 2)
    {
        printf("Errore argomento.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "r")) == NULL)
    {
        printf("Impossibile aprire file di testo %s\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while (!(feof(f)))
    {
        for (int i = 1; i <= 3; i++)
        {
            fscanf(f, "%s ", naz);
            aggiornaLista(&l, naz, i);
        }
    }

    fclose(f);

    stampa(l);

    return 0;
}
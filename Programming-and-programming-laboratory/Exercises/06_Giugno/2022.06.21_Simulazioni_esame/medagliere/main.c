#include <stdio.h>
#include <stdlib.h>

#include "listaNazioni.h"

int main(int argc, char *argv[])
{
    FILE *f;
    nomeNazione nm;
    Lista l;

    if (argc != 2)
    {
        printf("Errore argomento.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "r")) == NULL)
    {
        printf("Impossibile aprire file %s in lettura.\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while (!(feof(f)))
    {
        for (int i = 1; i <= 3; i++)
        {
            fscanf(f, "%s ", nm);
            aggiornaLista(&l, nm, i);
        }
    }

    fclose(f);

    stampaLista(l);

    return 0;
}
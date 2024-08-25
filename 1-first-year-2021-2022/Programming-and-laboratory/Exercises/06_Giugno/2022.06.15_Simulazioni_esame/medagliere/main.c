#include <stdio.h>
#include <stdlib.h>

#include "listaNazioni.h"

int main(int argc, char *argv[])
{
    FILE *f;
    nomeNazione n;
    Lista l;

    if (argc != 2)
    {
        printf("Errore, argomento non valido.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "r")) == NULL)
    {
        printf("Impossibile leggere il file di testo %s\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while (!(feof(f)))
    {
        for (int i = 1; i <= 3; i++)
        {
            fscanf(f, "%s ", n);
            aggiornaLista(&l, n, i);
        }
    }

    fclose(f);
    stampaLista(l);

    return 0;
}
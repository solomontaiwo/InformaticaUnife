#include <stdio.h>
#include <stdlib.h>

#include "listaPersone.h"

int main(int argc, char *argv[])
{
    Lista l;
    FILE *pf;
    Record r;

    if (argc != 2)
    {
        printf("Uso %s nome_file\n", argv[0]);
        exit(1);
    }

    pf = fopen(argv[1], "rb");
    if (pf == NULL)
    {
        printf("Errore appertura %s\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);
    while (fread(&r, sizeof(Record), 1, pf) == 1)
        aggiorna(&l, r);
    fclose(pf);

    stampa(l);
    return 0;
}
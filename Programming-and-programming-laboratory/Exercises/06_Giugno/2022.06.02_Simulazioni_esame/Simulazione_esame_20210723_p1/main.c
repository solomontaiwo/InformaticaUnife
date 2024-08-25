#include <stdio.h>
#include <stdlib.h>

#include "listaPersone.h"

int main(int argc, char *argv[])
{
    Lista l;
    FILE *pf;
    Record r;
    Data oggi;

    // ./greenpass eventi.dat
    if (argc != 5)
    {
        printf("Uso: %s nome_file giorno mese anno\n ", argv[0]);
        exit(1);
    }

    sscanf(argv[2], "%d", &oggi.giorno);
    sscanf(argv[3], "%d", &oggi.mese);
    sscanf(argv[4], "%d", &oggi.anno);

    pf = fopen(argv[1], "rb");
    if (pf == NULL)
    {
        printf("Errore apertura %s\n", argv[1]);
        exit(2);
    }
    nuovaLista(&l);
    while (fread(&r, sizeof(Record), 1, pf) == 1)
        aggiorna(&l, r, oggi);
    fclose(pf);

    stampa(l);
    return 0;
}
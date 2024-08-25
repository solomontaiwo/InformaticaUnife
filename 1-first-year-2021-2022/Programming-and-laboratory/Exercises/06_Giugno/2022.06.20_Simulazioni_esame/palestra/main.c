#include <stdio.h>
#include <stdlib.h>

#include "listaUtenti.h"

int main(int argc, char *argv[])
{
    FILE *f;
    CodiceFiscale cf;
    Lista l;
    Ingresso in;

    if (argc != 3)
    {
        printf("Errore argomenti\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile leggere il file %s in lettura.\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&cf, sizeof(CodiceFiscale), 1, f)) == 1)
        creaLista(&l, cf);

    fclose(f);

    if ((f = fopen(argv[2], "r")) == NULL)
    {
        printf("Impossibile leggere il file %s in lettura.\n", argv[2]);
        exit(3);
    }

    while (!(feof(f)))
    {
        fscanf(f, "%s %d ", in.cf, &in.attivita);
        aggiornaLista(&l, in);
    }

    fclose(f);

    stampa(l);

    return 0;
}
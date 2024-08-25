#include <stdio.h>
#include <stdlib.h>

#include "listaUtenti.h"

int main(int argc, char *argv[])
{
    FILE *f;
    cf codiceFiscale;
    Ingresso in;
    Lista l;

    if (argc != 3)
    {
        printf("Errore, argomenti non validi.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile leggere file binario %s\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&codiceFiscale, sizeof(cf), 1, f)) == 1)
    {
        creaLista(&l, codiceFiscale);
    }

    fclose(f);

    if ((f = fopen(argv[2], "r")) == NULL)
    {
        printf("Impossibile leggere file di testo %s\n", argv[2]);
        exit(3);
    }

    while (!(feof(f)))
    {
        fscanf(f, "%s", in.cf);
        fscanf(f, "%d ", &in.attivita);
        aggiorna(&l, in);
    }

    fclose(f);

    stampa(l);

    return 0;
}
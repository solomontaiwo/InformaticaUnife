#include <stdio.h>
#include <stdlib.h>

#include "listaUtenti.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Lista l;
    Iscritto is;
    Ingresso in;

    if (argc != 3)
    {
        printf("Errore, argomento mancante o errato.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile leggere il file binario.\n");
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&is, sizeof(Iscritto), 1, f)) == 1)
        creaLista(&l, is);

    fclose(f);

    if ((f = fopen(argv[2], "r")) == NULL)
    {
        printf("Impossibile leggere il file di testo.\n");
        exit(3);
    }

    while (!(feof(f)))
    {
        fscanf(f, "%s", in.cf);
        fscanf(f, "%d", &in.attivita);
        aggiornaLista(&l, in);
    }

    fclose(f);
    stampa(l);

    return 0;
}
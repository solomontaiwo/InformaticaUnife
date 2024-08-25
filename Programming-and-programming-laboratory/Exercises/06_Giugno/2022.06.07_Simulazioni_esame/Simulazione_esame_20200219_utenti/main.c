#include <stdio.h>
#include <stdlib.h>

#include "listaUtenti.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Record r;
    Lista l;

    if (argc != 3)
    {
        printf("Errore, argomenti mancanti o non validi.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire il file binario %s per lettura.\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&r, sizeof(Record), 1, f)) == 1)
        creaLista(&l, r);

    fclose(f);

    if ((f = fopen(argv[2], "r")) == NULL)
    {
        printf("Impossibile aprire il file di testo %s per lettura.\n", argv[2]);
        exit(3);
    }

    Chiamata c;

    while (!(feof(f)))
    {
        fscanf(f, "%s", c.numero);
        fscanf(f, "%d", &c.durata);
        aggiornaLista(&l, c);
    }

    stampa(l);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "listaEsami.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Studente s;
    Lista l;

    if (argc != 2)
    {
        printf("Errore, argomento non valido.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire il file di testo %s\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&s, sizeof(Studente), 1, f)) == 1)
        aggiorna(&l, s);

    fclose(f);

    stampa(l);

    return 0;
}
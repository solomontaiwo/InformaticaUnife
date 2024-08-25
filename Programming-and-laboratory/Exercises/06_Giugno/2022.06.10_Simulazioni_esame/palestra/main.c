#include <stdio.h>
#include <stdlib.h>

#include "listaUtenti.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Iscritto is;
    Lista l;
    Ingresso in;

    if (argc != 3)
    {
        printf("Errore, argomenti non validi.\n");
        exit(1);
    }

    nuovaLista(&l);

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire file binario %s in lettura\n", argv[1]);
        exit(2);
    }

    while ((fread(&is, sizeof(Iscritto), 1, f)) == 1)
        creaLista(&l, is);

    fclose(f);

    if ((f = fopen(argv[2], "r")) == NULL)
    {
        printf("Impossibile aprire file di testo %s in lettura\n", argv[2]);
        exit(3);
    }

    while (!feof(f))
    {
        fscanf(f, "%s", in.cf);
        fscanf(f, "%d", &in.attivita);
        aggiornaLista(&l, in);
    }

    fclose(f);

    stampa(l);

    return 0;
}
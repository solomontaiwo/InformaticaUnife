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
        printf("Errore, argomenti non validi. Inserire nome file binario e file di testo.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire file binario %s in lettura\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&codiceFiscale, sizeof(cf), 1, f)) == 1)
        creaLista(&l, codiceFiscale);

    fclose(f);

    if ((f = fopen(argv[2], "r")) == NULL)
    {
        printf("Impossibile aprire file di testo %s in lettura\n", argv[2]);
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
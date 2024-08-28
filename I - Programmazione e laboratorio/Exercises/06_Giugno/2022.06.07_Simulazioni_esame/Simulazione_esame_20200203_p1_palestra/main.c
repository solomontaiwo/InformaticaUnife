#include <stdio.h>
#include <stdlib.h>

#include "listaUtenti.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Utente u;
    Lista l;

    if (argc != 3)
    {
        printf("Errore, argomento non valido o non inserito.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile leggere file %s\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while (fread(&u, sizeof(Utente), 1, f) == 1)
    {
        creaLista(&l, u);
    }

    fclose(f);

    if ((f = fopen(argv[2], "rt")) == NULL)
    {
        printf("Impossibile leggere file %s\n", argv[2]);
        exit(3);
    }

    Entrata e;

    while (!feof(f))
    {
        fscanf(f, "%s", e.codiceFiscale);
        fscanf(f, "%d", &e.attivita);
        aggiorna(&l, e);
    }

    fclose(f);
    stampa(l);

    return 0;
}
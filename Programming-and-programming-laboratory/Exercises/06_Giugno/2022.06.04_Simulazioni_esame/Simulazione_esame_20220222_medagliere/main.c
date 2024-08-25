#include <stdio.h>
#include <stdlib.h>

#include "listaNazioni.h"

int main(int argc, char *argv[])
{
    Record r;
    Lista l;
    FILE *pft;
    int passaggi;

    if (argc != 2)
    {
        printf("Errore, immettere come argomento il nome del file che si vuole leggere.\n");
        exit(1);
    }

    if ((pft = fopen(argv[1], "rt")) == NULL)
    {
        printf("Impossibile leggere il file di testo %s\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while (!(feof(pft)))
    {
        for (passaggi = 1; passaggi <= 3; passaggi++)
        {
            fscanf(pft, "%s", r.Nazione);
            aggiorna(&l, r.Nazione, passaggi);
        }
    }

    fclose(pft);
    stampa(l);
    
    return 0;
}
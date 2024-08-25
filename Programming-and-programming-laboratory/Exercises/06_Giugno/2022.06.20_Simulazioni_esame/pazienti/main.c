#include <stdio.h>
#include <stdlib.h>

#include "listaPazienti.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Rilevazione r;
    Lista l;

    if (argc != 2)
    {
        printf("Errore, uso errato argomento.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire in lettura il file %s\n", argv[1]);
        exit(2);
    }

    while ((fread(&r, sizeof(Rilevazione), 1, f)) == 1)
        aggiorna(&l, r);

    fclose(f);

    stampa(l);

    return 0;
}
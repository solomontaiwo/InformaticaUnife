#include <stdio.h>
#include <stdlib.h>

#include "listaVeicoli.h"

int main(int argc, char *argv[])
{
    FILE *f;
    Accesso a;
    Lista l;

    if (argc != 2)
    {
        printf("Errore argomento.\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile aprire in lettura il file binario.\n");
        exit(2);
    }

    nuovaLista(&l);

    while ((fread(&a, sizeof(Accesso), 1, f)) == 1)
        creaLista(&l, a);

    fclose(f);
    stampa(l);

    return 0;
}
#include <stdio.h>

#include "massimo.h"

int main(int argc, char *argv[])
{
    Lista numeriCasuali;

    generaLista(&numeriCasuali);

    stampa(numeriCasuali);

    printf("Il numero piu' grande all'interno della lista e' %d.\n", massimo(numeriCasuali));

    return 0;
}
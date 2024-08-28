#include <stdio.h>

#include "listToArray.h"

int main(int argc, char *argv[])
{
    Lista numeriCasuali;

    generaLista(&numeriCasuali);

    stampa(numeriCasuali);

    printf("%p\n", listToArray(numeriCasuali));

    return 0;
}
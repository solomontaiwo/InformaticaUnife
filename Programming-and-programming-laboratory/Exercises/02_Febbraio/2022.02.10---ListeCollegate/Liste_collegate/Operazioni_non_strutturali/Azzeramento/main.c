#include <stdio.h>
#include <stdlib.h>
#include "listaCollegata.h"

int main(int argc, char *argv[])
{
    Lista l;

    listaNonOrdinata(&l, 6);

    stampa(l);

    azzera(l);

    stampa(l);
}
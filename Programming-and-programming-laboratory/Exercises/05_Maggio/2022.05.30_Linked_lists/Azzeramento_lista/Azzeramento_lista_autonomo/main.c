#include <stdlib.h>
#include <time.h>
#include "azzeramento.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    Lista nuovaLista;

    generaLista(&nuovaLista, 1 + rand() % (10 - 1 + 1));

    stampa(nuovaLista);

    azzera(nuovaLista);

    stampa(nuovaLista);

    return 0;
}
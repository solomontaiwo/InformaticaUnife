#include <stdlib.h>
#include <time.h>

#include "struttureListeCollegate.h"

int main(int argc, char *argv[])
{
    Lista nuovaLista;

    srand(time(NULL));

    inizializzaLista(&nuovaLista);
    for (int i = 0; i < 10; i++)
        insTesta(&nuovaLista, 1 + rand() % (100 - 1 + 1));

    stampa(nuovaLista);

    ordinaLista(&nuovaLista);

    stampa(nuovaLista);

    return 0;
}
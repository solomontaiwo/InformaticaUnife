#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listeSequenziali.h"

int main(int argc, char *argv[])
{

    srand(time(NULL));

    Lista l;

    inizializzaLista(&l);

    insOrd(&l, 4);

    insTesta(&l, 5);

    printf("Grandezza della lista: %d\n", lunghezza(l));

    stampa(l);

    insOrd(&l, 1);

    stampa(l);

    elim1(&l, 1);

    stampa(l);

    insTesta(&l, 1 + rand() % (10 - 1 + 1));

    stampa(l);

    return 0;
}
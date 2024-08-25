#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listeSequenzialiNuove.h"

int main(int argc, char *argv[])
{

    srand(time(NULL));

    Lista l;

    inizializza(&l);

    insTesta(&l, 8);

    stampa(l);

    insOrd(&l, 5);

    stampa(l);

    elimElemento1(&l, 8);

    stampa(l);

    insOrd(&l, 50 + rand() % (70 - 50 + 1));

    stampa(l);

    return 0;
}
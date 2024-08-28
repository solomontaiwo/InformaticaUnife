#include "funzioniConcatena.h"

int main(int argc, char *argv[])
{
    Lista l;

    inizializza(&l);

    insTesta(&l, 4);

    insTesta(&l, 8);

    insCoda(&l, 1);

    insOrd(&l, 5);

    insOrd(&l, 2);

    insOrd(&l, 9);

    insOrd(&l, 1);

    stampa(l);

    return 0;
}
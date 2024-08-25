#include <stdio.h>

#include "funzioniListeCollegateAutonomia.h"

int main(int argc, char *argv[])
{
    Lista l;

    creaLista(&l);

    insTesta(&l, 5);

    stampa(l);

    insOrd(&l, 2);

    stampa(l);

    elimTutti(&l, 5);

    stampa(l);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "listeSequenzialiPrototipi.h"

int main(int argc, char *argv[])
{

    Lista capoLista;

    inizializza(&capoLista);

    insTesta(&capoLista, 3);

    insTesta(&capoLista, 9);

    stampa(capoLista);

    insOrd(&capoLista, 1);

    stampa(capoLista);

    elim1(&capoLista, 3);

    stampa(capoLista);

    elimTutti(&capoLista, 9);

    stampa(capoLista);
}
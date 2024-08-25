#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listeSequenzialiMarzoAutonomo.h"

int main(int argc, char *argv[])
{
    Lista listone;

    nuovaLista(&listone);
    insTesta(&listone, 8);
    insOrd(&listone, 4);
    stampa(listone);
    return 0;
}
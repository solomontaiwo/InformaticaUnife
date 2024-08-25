#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(int argc, char *argv[])
{
    Lista peppina;

    inizializza(&peppina);

    insOrd(&peppina, 3);
    insOrd(&peppina, 2);
    insOrd(&peppina, 9);
    insTesta(&peppina, 15);

    stampa(peppina);

    elimina1(&peppina, 15);

    stampa(peppina);
}
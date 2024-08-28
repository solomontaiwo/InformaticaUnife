#include <stdlib.h>

#include "ordinato.h"

int main()
{
    Lista l;

    nuovaLista(&l);

    insTesta(&l, 5);

    insOrd(&l, 2);

    insTesta(&l, 99);

    insOrd(&l, 52);

    stampa(l);

    elimTesta(&l);

    return 0;
}
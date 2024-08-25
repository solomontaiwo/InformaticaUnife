#include "funzioniListeCollegate.h"
#include <time.h>
#include <stdlib.h>

int main(void)
{
    Lista nuova;

    creaLista(&nuova);

    srand(time(NULL));

    insTesta(&nuova, 1 + rand() % (50 - 1 + 1));

    insTesta(&nuova, 1 + rand() % (50 - 1 + 1));

    insTesta(&nuova, 1 + rand() % (50 - 1 + 1));

    insOrd(&nuova, 1 + rand() % (50 - 1 + 1));

    insOrd(&nuova, 1 + rand() % (50 - 1 + 1));

    insOrd(&nuova, 5);

    elim1(&nuova, 5);

    stampa(nuova);
}
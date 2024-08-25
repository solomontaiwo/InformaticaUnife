#include "insTesta.h"
#include "listaCollegata.h"
#include "insOrd.h"

void insertionSort(Lista *pl1)
{
    Lista l2;
    nuovaLista(&l2);

    while (*pl1)
    {
        insOrd(&l2, (*pl1)->dato);
        elimTesta(pl1);
    }
    *pl1 = l2;
}
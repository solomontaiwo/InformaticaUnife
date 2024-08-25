#include "varieFunzioniListeCollegate.h"

void elimTesta(Lista *pl)
{
    Nodo *aux = *pl;
    *pl = (*pl)->next;
    free(aux);
}

Lista *ricerca(Lista *pl, int numero)
{
    while (*pl)
    {
        if ((*pl)->dato == numero)
            break;
        else
        {
            pl = &(*pl)->next;
        }
    }
    return pl;
}

Lista *ricercaPerInsOrd(Lista *pl, int numero)
{
    while (*pl)
    {
        if ((*pl)->dato > numero)
            break;
        else
        {
            pl = &(*pl)->next;
        }
    }
    return pl;
}

void insOrd(Lista *pl, Dato d)
{
    ricercaPerInsOrd(pl, d);
    insTesta(pl, d);
}

void nuovaLista(Lista *pl)
{
    pl = NULL;
}

void insertionSort(Lista *pl1)
{
    Lista l2;
    nuovaLista(&l2);

    while (*pl1)
    {
        insOrd(&l2, (*pl1)->dato);
        elimTesta(&pl1);
    }

    *pl1 = l2;
}
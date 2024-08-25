#include <stdio.h>
#include <stdlib.h>
#include "dichiarazioniListeCollegate.h"

int vuota(Lista l)
{
    return l == NULL;
}

int piena(Lista l)
{
    return 0;
}

int lunghezza(Lista l)
{
    int c = 0;
    while (l)
    {
        c++;
        l = l->next;
    }
    return c;
}

void inizializza(Lista *pl)
{
    *pl = NULL;
}

void listaNonOrdinata(Lista *pl, int numeroElementi)
{
    int array[] = {8, 4, 1, 11, 6, 9};
    int i;
    for (i = 0; i < numeroElementi; i++)
    {
        (*pl) = (Nodo *)malloc(sizeof(Nodo));
        (*pl)->dato = array[i];
        (*pl)->next = NULL;
        pl = &(*pl)->next;
    }
}

void insTesta(Lista *pl, Dato d)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    if (aux == NULL)
        exit(100);
    else
    {
        aux->dato = d;
        aux->next = *pl;
        *pl = aux;
    }
}

Lista *ricerca(Lista *pl, Dato d)
{
    while (*pl)
    {
        if ((*pl)->dato == d)
            break;
        else
            pl = &(*pl)->next;
    }
    return pl;
}

Lista *ricercaInsOrd(Lista *pl, Dato d)
{
    while (*pl)
    {
        if ((*pl)->dato > d)
            break;
        else
            pl = &(*pl)->next;
    }
    return pl;
}

Lista *ricercaInsCoda(Lista *pl)
{
    while (*pl)
        pl = &(*pl)->next;
    return pl;
}

void insOrd(Lista *pl, Dato d)
{
    pl = ricercaInsOrd(pl, d);
    insTesta(pl, d);
}

void insertionSort(Lista *pl1)
{
    Lista l2;
    inizializza(&l2);

    while (*pl1)
    {

        insOrd(&l2, (*pl1)->dato);
        elimTesta(pl1);
    }
    *pl1 = l2;
}

void insCoda(Lista *pl, Dato d)
{
    pl = ricercaInsCoda(pl);
    insTesta(pl, d);
}

void elimTesta(Lista *pl)
{
    Nodo *aux = *pl;
    *pl = (*pl)->next;
    free(aux);
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d ", l->dato);
        l = l->next;
    }
    puts("");
}

int elim1(Lista *pl, int d)
{
    pl = ricerca(pl, d);
    if (*pl)
    {
        elimTesta(pl);
        return 1;
    }
    else
        return 0;
}

void elimTutti(Lista *pl, int d)
{
    while (*pl)
    {
        pl = ricerca(pl, d);
        if (*pl)
            elimTesta(pl);
    }
}
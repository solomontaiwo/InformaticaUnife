#include <stdio.h>
#include <stdlib.h>
#include "tutteFunzioniListeCollegate.h"

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

void nuovaLista(Lista *pl)
{
    *pl = NULL;
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

void listaNonOrdinata(Lista *pl, int numeroElementi)
{
    int array[] = {8, 0, 41, 2, 55, 3, 4, 6};
    int i;

    for (i = 0; i < numeroElementi; i++)
    {
        *pl = (Nodo *)malloc(sizeof(Nodo));
        (*pl)->dato = array[i];
        (*pl)->next = NULL;
        pl = &(*pl)->next;
    }
}

Lista *ricerca(Lista *pl, Dato d)
{
    while (*pl)
    {
        if ((*pl)->dato == d)
            break;
        else
        {
            pl = &(*pl)->next;
        }
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
        {
            pl = &(*pl)->next;
        }
    }
    return pl;
}

Lista *ricercaInsCoda(Lista *pl, Dato d)
{
    while (*pl)
    {
        pl = &(*pl)->next;
    }
    return pl;
}

void insTesta(Lista *pl, Dato d)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    if (aux == NULL)
        exit(100);
    aux->dato = d;
    aux->next = *pl;
    *pl = aux;
}

void insOrd(Lista *pl, Dato d)
{
    pl = ricercaInsOrd(pl, d);
    insTesta(pl, d);
}

void insCoda(Lista *pl, Dato d)
{
    pl = ricercaInsCoda(pl, d);
    insTesta(pl, d);
}

void elimTesta(Lista *pl)
{
    Nodo *aux = *pl;
    *pl = (*pl)->next;
    free(aux);
}

int elim1(Lista *pl, Dato d)
{
    pl = ricerca(pl, d);
    if (pl)
    {
        elimTesta(pl);
        return 1;
    }
    else
        return 0;
}

void elimTutti(Lista *pl, Dato d)
{
    while (*pl)
    {
        pl = ricerca(pl, d);
        if (*pl)
        {
            elimTesta(pl);
        }
    }
}
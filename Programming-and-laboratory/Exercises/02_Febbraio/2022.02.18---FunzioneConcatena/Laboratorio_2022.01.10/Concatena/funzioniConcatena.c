#include <stdio.h>
#include <stdlib.h>
#include "funzioniConcatena.h"

int vuota(Lista l)
{
    return l == NULL;
}

int piena(Lista l)
{
    return 0;
}

void inizializza(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Dato d)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->dato = d;
    aux->next = *pl;
    *pl = aux;
}

void insCoda(Lista *pl, Dato d)
{
    while (*pl)
    {
        pl = &(*pl)->next;
    }

    insTesta(pl, d);
}

void concatena(Lista *pl1, Lista l2)
{
    while (l2)
    {
        insCoda(pl1, l2->dato);
        l2 = l2->next;
    }
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

int ricerca(Lista l, Dato d)
{
    while (l)
    {
        if (l->dato == d)
        {
            return 1;
        }
        else
            l = l->next;
    }
    return 0;
}

void insOrd(Lista *pl, Dato d)
{
    while (*pl)
    {
        if ((*pl)->dato > d)
            break;
        else
            (pl = &(*pl)->next);
    }
    insTesta(pl, d);
}
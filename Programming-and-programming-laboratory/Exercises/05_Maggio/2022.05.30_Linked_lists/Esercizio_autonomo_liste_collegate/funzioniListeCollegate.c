#include <stdio.h>
#include <stdlib.h>

#include "funzioniListeCollegate.h"

int vuota(Lista l)
{
    return l == NULL;
}

int piena(Lista l)
{
    return 0;
}

void creaLista(Lista *pl)
{
    *pl = NULL;
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d ", l->d);
        l = l->next;
    }
    puts("");
}

Lista *ricerca(Lista *pl, int numero)
{
    while (*pl)
    {
        if ((*pl)->d == numero)
            break;
        *pl = (*pl)->next;
    }
    return pl;
}

Lista *ricercaOrd(Lista *pl, int numero)
{
    while (*pl)
    {
        if ((*pl)->d > numero)
            break;
        *pl = (*pl)->next;
    }
    return pl;
}

void insTesta(Lista *pl, int numero)
{
    Nodo *nuovaTesta = (Nodo *)malloc(sizeof(Nodo));
    nuovaTesta->d = numero;
    nuovaTesta->next = *pl;
    *pl = nuovaTesta;
}

void insOrd(Lista *pl, int numero)
{
    pl = ricercaOrd(pl, numero);
    insTesta(pl, numero);
}

void elimTesta(Lista *pl)
{
    Nodo *nuovaTesta = (Nodo *)malloc(sizeof(Nodo));
    *pl = (*pl)->next;
    free(nuovaTesta);
}

int elim1(Lista *pl, int numero)
{
    pl = ricerca(pl, numero);
    if (*pl)
    {
        elimTesta(pl);
        return 1;
    }
    else
        return 0;
}

void elimTutti(Lista *pl, int numero)
{
    pl = ricerca(pl, numero);
    if (*pl)
    {
        elimTesta(pl);
    }
}
#include <stdio.h>
#include <stdlib.h>

#include "ordinato.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

int listaVuota(Lista l)
{
    return l == NULL;
}

int listaPiena(Lista l)
{
    return 0;
}

void insTesta(Lista *pl, Dato d)
{
    Nodo *nuovaTesta = (Nodo *)malloc(sizeof(Nodo));
    nuovaTesta->d = d;
    nuovaTesta->next = *pl;
    *pl = nuovaTesta;
}

Lista *ricercaOrd(Lista *pl, int numero)
{
    while (*pl)
    {
        if ((*pl)->d > numero)
            break;
        pl = &(*pl)->next;
    }
    return pl;
}

Lista *ricerca(Lista *pl, int numero)
{
    while (*pl)
    {
        if (((*pl)->d) == numero)
            break;
        pl = &(*pl)->next;
    }
    return pl;
}

void insOrd(Lista *pl, int numero)
{
    pl = ricercaOrd(pl, numero);
    insTesta(pl, numero);
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

void elimTesta(Lista *pl)
{
    Nodo *testaElim = *pl;
    *pl = (*pl)->next;
    free(testaElim);
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
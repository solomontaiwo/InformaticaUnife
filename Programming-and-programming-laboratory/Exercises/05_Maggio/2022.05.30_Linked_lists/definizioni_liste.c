#include <stdlib.h>

#include "tipi_liste_collegate.h"

int vuota(Lista l)
{
    return l = NULL;
}

int piena(Lista l)
{
    return 0;
}

void stampa(Lista l)
{
    while (l != NULL)
    {
        printf("%d ", l->dato);
        l = l->next;
    }
    puts("");
}

void elimTesta(Lista *pl)
{
    Nodo *aux = *pl;
    *pl = (*pl)->next;
    free(aux);
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

void listaNuova(Lista *pl)
{
    *pl = NULL;
}

Lista *ricerca(Lista *pl, Dato d)
{
    while (*pl)
    {
        if ((*pl)->dato == d)
            break;
        pl = &(*pl)->next;
    }
    return pl;
}

Lista *ricercaOrd(Lista *pl, Dato d)
{
    while (*pl)
    {
        if ((*pl)->dato > d)
            break;
        pl = &(*pl)->next;
    }
    return pl;
}

void insOrd(Lista *pl, int d)
{
    pl = ricercaOrd(pl, d);
    insTesta(pl, d);
}

void insTesta(Lista *pl, Dato d)
{
    Nodo *nuovaTesta = (Nodo *)malloc(sizeof(Nodo));
    nuovaTesta->dato = d;
    nuovaTesta->next = *pl;
    *pl = nuovaTesta;
}
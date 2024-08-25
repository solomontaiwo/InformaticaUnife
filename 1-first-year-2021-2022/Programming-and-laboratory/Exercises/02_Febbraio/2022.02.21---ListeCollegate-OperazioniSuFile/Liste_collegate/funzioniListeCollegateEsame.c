#include "funzioniListeCollegateEsame.h"
#include <stdio.h>
#include <stdlib.h>

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

int ricerca(Lista *pl, int numero)
{
    while (*pl)
    {
        if ((*pl)->dato == numero)
            return 1;
        else
            pl = &(*pl)->next;
    }
    return 0;
}

Lista *ricercaElim1(Lista *pl, int numero)
{
    while (*pl)
    {
        if ((*pl)->dato == numero)
            break;
        else
            pl = &(*pl)->next;
    }
    return pl;
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

void insTesta(Lista *pl, int numero)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    if (aux == NULL)
        exit(100);
    aux->dato = numero;
    aux->next = *pl;
    *pl = aux;
}

void elimTesta(Lista *pl)
{
    Nodo *aux = *pl;
    *pl = (*pl)->next;
    free(aux);
}

int elim1(Lista *pl, int numero)
{
    pl = ricercaElim1(pl, numero);
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
    while (*pl)
    {
        pl = ricercaElim1(pl, numero);

        if (*pl)
            elimTesta(pl);
    }
}

Lista *ricercaOrdinato(Lista *pl, int numero)
{
    while (*pl)
    {
        if ((*pl)->dato > numero)
            break;
        else
            pl = &(*pl)->next;
    }
    return pl;
}

void insOrd(Lista *pl, int numero)
{
    pl = ricercaOrdinato(pl, numero);
    insTesta(pl, numero);
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

Lista *ricercaCoda(Lista *pl)
{
    while (*pl)
        pl = &(*pl)->next;
    return pl;
}

void insCoda(Lista *pl, int numero)
{
    pl = ricercaCoda(pl);
    insTesta(pl, numero);
}
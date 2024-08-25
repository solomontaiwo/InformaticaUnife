#include <stdio.h>
#include <stdlib.h>

#include "struttureListeCollegate.h"

void inizializzaLista(Lista *pl)
{
    *pl = NULL;
}

int vuota(Lista l)
{
    return l == NULL;
}

int piena(Lista l)
{
    return 0;
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d ", l->d);
        l = l->next;
    }
    printf("\n");
}

void insTesta(Lista *pl, int numero)
{
    Nodo *nuovaTesta = (Nodo *)malloc(sizeof(Nodo));
    nuovaTesta->d = numero;
    nuovaTesta->next = *pl;
    *pl = nuovaTesta;
}

void elimTesta(Lista *pl)
{
    Nodo *aux = *pl;
    (*pl) = (*pl)->next;
    free(aux);
}

void insOrd(Lista *pl, int numero)
{
    pl = ricercaOrd(pl, numero);
    if (*pl)
        insTesta(pl, numero);
}

Lista *ricerca(Lista *pl, int numero)
{
    while (*pl)
    {
        if ((*pl)->d == numero)
        {
            return pl;
        }
    }
    return 0;
}

Lista *ricercaOrd(Lista *pl, int numero)
{
    while (*pl)
    {
        if ((*pl)->d > numero)
        {
            return pl;
        }
    }
    return 0;
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

void ordinaLista(Lista *pl)
{
    int scambiato;
    Lista *ptr1;
    Lista *lptr = NULL;

    if (vuota(*pl))
        return;

    do
    {
        scambiato = 0;
        ptr1 = pl;

        while ((*ptr1)->next != NULL)
        {
            if ((*ptr1)->d > (*ptr1)->next->d)
            {
                swap((*ptr1), (*ptr1)->next);
                scambiato = 1;
            }
            ptr1 = &(*ptr1)->next;
        }
        lptr = ptr1;
    } while (scambiato);
}

void swap(Nodo *a, Nodo *b)
{
    int temp = a->d;
    a->d = b->d;
    b->d = temp;
}
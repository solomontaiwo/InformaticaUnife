#include <stdio.h>
#include <stdlib.h>

#include "scritturaBinario.h"

void creaLista(Lista *pl)
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

void insOrd(Lista *pl, int numero)
{
    pl = ricercaOrd(pl, numero);
    if (*pl)
    {
        insTesta(pl, numero);
    }
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

void swap(Nodo *a, Nodo *b)
{
    int temp = a->d;
    a->d = b->d;
    b->d = temp;
}

void ordina(Lista *pl)
{
    Lista *prima;
    Lista *seconda = NULL;

    int scambiato;

    if (vuota(*pl))
        return;

    do
    {
        scambiato = 0;
        prima = pl;
        {
            while ((*prima)->next != NULL)
            {
                if ((*prima)->d > (*prima)->next->d)
                {
                    swap((*prima), (*prima)->next);
                    scambiato = 1;
                }
                prima = &(*prima)->next;
            }
            seconda = prima;
        }
    } while (scambiato);
}
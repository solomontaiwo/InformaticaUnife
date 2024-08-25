#include "listeCollegatePrototipi.h"
#include <stdio.h>
#include <stdlib.h>

int vuota(Lista l)
{
    return l == NULL;
}

int piena(Lista l)
{
    return 0; // la lista collegata non puo' essere piena
}

void listaNonOrdinata(Lista *pl, int lunghezza)
{
    int array[] = {8, 4, 11, 6, 9, 5, 1};
    int i;

    for (i = 0; i < lunghezza; i++)
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
    aux->dato = d;
    aux->next = *pl;
    *pl = aux;
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

void stampa(Lista l)
{
    while (l)
    {
        printf("%d ", l->dato);
        l = l->next;
    }
    puts("");
}

// Operazioni strutturali derivate

void elimTesta(Lista *pl)
{
    Nodo *aux = *pl;
    *pl = (*pl)->next;
    free(aux);
}

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

Lista *ricerca(Lista *pl, int numero)
{
    while (*pl)
    {
        if ((*pl)->dato == numero)
        {
            break;
        }
        else
        {
            pl = &(*pl)->next;
        }
        return pl;
    }
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
void insOrd(Lista *pl, int numero)
{
    pl = ricercaPerInsOrd(pl, numero);
    insTesta(pl, numero);
}

void insertionSort(Lista *pl1)
{
    Lista l2;
    nuovaLista(&l2);

    while (*pl1)
    {
        insOrd(&l2, (*pl1)->dato);
        elimTesta(pl1);
    }
    *pl1 = l2;
}

Lista *ricercaPerInsCoda(Lista *pl, int numero)
{
    while (*pl)
        pl = &(*pl)->next;
    return pl;
}

void insCoda(Lista *pl, int numero)
{
    pl = ricercaPerInsCoda(pl, numero);
    insTesta(pl, numero);
}
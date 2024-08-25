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
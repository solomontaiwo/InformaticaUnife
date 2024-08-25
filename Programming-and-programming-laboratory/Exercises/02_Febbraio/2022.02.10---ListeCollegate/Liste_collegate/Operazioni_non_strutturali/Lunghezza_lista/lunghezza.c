#include <stdio.h>
#include <stdlib.h>
#include "lunghezza.h"

typedef Nodo *Lista;

int lunghezza(Lista l)
{
    int lunghezza = 0;
    while (l)
    {
        lunghezza++;
        l = l->next;
    }
    return lunghezza;
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

void listaNonOrdinata(Lista *pl, int n)
{
    int valori[] = {5, 1, 9, 11, 78, 45, 3, 66};
    int i;
    for (i = 0; i < n; i++)
    {
        (*pl) = (Nodo *)malloc(sizeof(Nodo));
        (*pl)->dato = valori[i];
        (*pl)->next = NULL;
        pl = &(*pl)->next;
    }
}
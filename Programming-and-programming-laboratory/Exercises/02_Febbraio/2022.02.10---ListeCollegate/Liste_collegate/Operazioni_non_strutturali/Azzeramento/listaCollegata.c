#include <stdio.h>
#include <stdlib.h>
#include "listaCollegata.h"

void azzera(Lista l)
{
    while (l)
    {
        l->dato = 0;
        l = l->next;
    }
}

void listaNonOrdinata(Lista *pl, int n)
{
    int array[] = {9, 2, 4, 3, 6, 7};
    int i;
    for (i = 0; i < n; i++)
    {
        (*pl) = (Nodo *)malloc(sizeof(Nodo));
        (*pl)->dato = array[i];
        (*pl)->next = NULL;
        pl = &(*pl)->next;
    }
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
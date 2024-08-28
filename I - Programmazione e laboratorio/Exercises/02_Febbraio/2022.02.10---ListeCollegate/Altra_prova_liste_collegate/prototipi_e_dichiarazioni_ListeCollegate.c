#include <stdio.h>
#include <stdlib.h>
#include "prototipi_e_dichiarazioni_ListeCollegate.h"

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
    while (l) // oppure while (l != NULL) //
    {
        printf("%d ", l->dato);
        l = l->next;
    }
    puts("");
}

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
    int array[] = {8, 1, 9, 7, 6, 11, 58, 7};
    int i;

    for (i = 0; i < n; i++)
    {
        (*pl) = (Nodo *)malloc(sizeof(Nodo));
        (*pl)->dato = array[i];
        (*pl)->next = NULL;
        pl = &(*pl)->next;
    }
}
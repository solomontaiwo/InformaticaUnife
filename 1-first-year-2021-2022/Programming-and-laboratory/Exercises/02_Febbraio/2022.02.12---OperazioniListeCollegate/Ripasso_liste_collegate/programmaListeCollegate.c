#include "programmaListeCollegate.h"
#include <stdio.h>
#include <stdlib.h>

int vuota(Lista l)
{
    return l == NULL;
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

void listaNonOrdinata(Lista *pl, int numeroElementi)
{
    int array[] = {9, 8, 3, 44, 1, 8, 46};
    int i;

    for (i = 0; i < numeroElementi; i++)
    {
        (*pl) = (Nodo *)malloc(sizeof(Nodo));
        (*pl)->dato = array[i];
        (*pl)->next = NULL;
        pl = &(*pl)->next;
    }
}
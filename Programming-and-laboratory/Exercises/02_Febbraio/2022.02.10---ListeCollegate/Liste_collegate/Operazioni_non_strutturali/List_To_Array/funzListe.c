#include "funzListe.h"
#include <stdlib.h>
#include <stdio.h>

int vuota(Lista l)
{
    return l == NULL;
}

int piena(Lista l)
{
    return 0;
}

void generaListaNonOrdinata(Lista *pl, int numero)
{
    int array[] = {7, 9, 1, 5, 6};
    int i;
    for (i = 0; i < numero; i++)
    {
        (*pl) = (Nodo *)malloc(sizeof(Nodo));
        (*pl)->dato = array[i];
        (*pl)->next = NULL;
        pl = &(*pl)->next;
    }
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

int* listToArray(Lista l)
{
    int n = lunghezza(l);
    int *array, i = 0;
    array = (int *)malloc(sizeof(int) * n);
    while (l)
    {
        array[i] = l->dato;
        i++;
        l = l->next;
    }
    return array;
}
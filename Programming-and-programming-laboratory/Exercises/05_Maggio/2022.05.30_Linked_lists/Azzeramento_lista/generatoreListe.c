#include <stdlib.h>
#include <stdio.h>

#include "generatoreListe.h"

void generatoreListe(Lista *pl, int n)
{

    int a[] = {5, 4, 8, 11, 95, 46, 1};
    int i;

    for (i = 0; i < n; i++)
    {
        (*pl) = (Nodo *)malloc(sizeof(Nodo));
        (*pl)->dato = a[i];
        (*pl)->next = NULL;
        pl = &(*pl)->next;
    }
}
void azzera(Lista l)
{
    while (l)
    {
        l->dato = 0;
        l = l->next;
    }
}
void stampa(Lista l)
{
    while (l)
    {
        printf("%d ", l->dato);
        l = l->next;
    }
    printf("\n");
}
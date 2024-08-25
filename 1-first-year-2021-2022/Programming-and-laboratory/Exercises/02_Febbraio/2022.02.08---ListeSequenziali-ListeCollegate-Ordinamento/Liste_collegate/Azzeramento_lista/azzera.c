#include <stdio.h>

typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

// inizializzazione lista non ordinata di 6 elementi
void listaNonOrdinata(Lista *pl, int n)
{
    int a[] = {6, 1, 9, 0, 2, 4, 7, 8, 3, 5};
    int i;

    for (i = 0; i < n; i++) {
        (*pl) = (Nodo*)malloc(sizeof(Nodo));
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
}
#include <stdio.h>
#include <stdlib.h>

typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

int vuota(Lista l)
{
    return l == 0;
}

void listaNonOrdinata(Lista *pl, int n)
{
    int a[] = {5, 1, 9, 1, 4, 7};
    int i;

    for (i = 0; i < n; i++)
    {
        (*pl) = (Nodo *)malloc(sizeof(Nodo));
        (*pl)->dato = a[i];
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

void azzera(Lista l)
{
    while (l)
    {
        l->dato = 0;
        l = l->next;
    }
}

int main()
{
    Lista l;

    listaNonOrdinata(&l, 6);

    azzera(l);

    stampa(l);
}
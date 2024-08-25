#include <stdio.h>
#include <stdlib.h>

typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

int piena(Lista l)
{
    return 0;
}

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

void listaNonOrdinata(Lista *pl, int numeroElementi)
{
    int valori[] = {50, 2, 9, 77, 0, 45, 6};
    int i;
    for (i = 0; i < numeroElementi; i++)
    {
        (*pl) = (Nodo *)malloc(sizeof(Nodo));
        (*pl)->dato = valori[i];
        (*pl)->next = NULL;
        pl = &(*pl)->next;
    }
}

int massimo(Lista l)
{
    int max = 0;
    while (l)
    {
        if (l->dato > max)
        {
            max = l->dato;
            l = l->next;
        }
        else
            l = l->next;
    }
    return max;
}
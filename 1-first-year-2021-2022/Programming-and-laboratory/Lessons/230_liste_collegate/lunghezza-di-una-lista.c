#include <stdio.h>

typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

#include "generatoreListe.h"

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

int main()
{
    Lista l;
    listaNonOrdinata(&l, 5);
    printf("%d\n", lunghezza(l));
    return 0;
}
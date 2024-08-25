#include <stdio.h>
#include <stdlib.h>

typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

#include "generatoreListe.h"

void azzera(Lista l)
{
    while (l)
    {
        // agisco sulla testa di l l->dato
        l->dato = 0;
        // assegno a l la sua coda, ossia passo all'elemento successivo (l->next)
        l = l->next;
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d\n", l->dato);
        l = l->next;
    }
}

int main()
{
    Lista l;
    listaNonOrdinata(&l, 6);
    azzera(1);
    return 0;
}
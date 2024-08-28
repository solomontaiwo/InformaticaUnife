#include <stdlib.h>

typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void insTesta(Lista *pl, Dato d)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));

    if (aux == NULL)
        exit(100); // allocazione non riuscita
    aux->dato = d;
    aux->next = *pl;
    *pl = aux;
}
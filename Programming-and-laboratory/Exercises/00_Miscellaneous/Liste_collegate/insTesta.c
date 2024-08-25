#include <stdlib.h>

typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void insTesta(Lista *pl, Dato numero)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    if (aux == NULL)
        exit(100);
    aux->dato = numero;
    aux->next = *pl;
    *pl = aux;
}
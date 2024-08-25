#include <stdlib.h>
#include "listaCollegata.h"

void insTesta(Lista *pl, Dato d)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    if (aux == NULL)
        exit(100);
    aux->dato = d;
    aux->next = *pl;
    *pl = aux;
}
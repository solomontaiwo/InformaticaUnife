#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "massimo.h"

void generaLista(Lista *pl)
{

    srand(time(NULL));

    int numeri[20];

    for (int i = 0; i < 20; i++)
    {
        numeri[i] = 1 + rand() % (255 - 1 + 1);
    }

    for (int i = 0; i < 20; i++)
    {
        (*pl) = (Nodo *)malloc(sizeof(Nodo));
        (*pl)->dato = numeri[i];
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
int massimo(Lista l)
{
    int massimo = 0;
    while (l)
    {
        if (l->dato > massimo)
        {
            massimo = l->dato;
        }
        l = l->next;
    }
    return massimo;
}
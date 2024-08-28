#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lunghezza.h"

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
int lunghezza(Lista l)
{
    int conta = 0;
    while (l)
    {
        conta++;
        l = l->next;
    }
    return conta;
}
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "azzeramento.h"

void generaLista(Lista *pl, int lunghezza)
{
    int a[10];

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        a[i] = 1 + rand() % (10 - 1 + 1);
    }

    for (int i = 0; i < lunghezza; i++)
    {
        (*pl) = (Nodo *)malloc(sizeof(Nodo));
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
    puts("");
}
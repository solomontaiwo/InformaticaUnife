#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "reverse.h"

void generaLista(Lista *pl)
{
    srand(time(NULL));

    for (int i = 0; i < 6; i++)
    {
        (*pl) = (Nodo *)malloc(sizeof(Nodo));
        (*pl)->d = 1 + rand() % (255 - 1 + 1);
        (*pl)->next = NULL;
        pl = &(*pl)->next;
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d ", l->d);
        l = l->next;
    }
    puts("");
}

void insTesta(Lista *pl, int numero)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    testa->d = numero;
    testa->next = *pl;
    *pl = testa;
}

void reverse(Lista l1, Lista *pl2)
{
    *pl2 = NULL;
    
    while (l1)
    {
        insTesta(pl2, l1->d);
        l1 = l1->next;
    }
}
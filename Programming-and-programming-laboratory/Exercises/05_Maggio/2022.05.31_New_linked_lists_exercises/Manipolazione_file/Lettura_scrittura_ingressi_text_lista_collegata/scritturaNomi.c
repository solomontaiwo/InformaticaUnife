#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "scritturaNomi.h"

void inizializzaLista(Lista *pl)
{
    *pl = NULL;
}

int vuota(Lista l)
{
    return l == NULL;
}

int piena(Lista l)
{
    return 0;
}

void insTesta(Lista *pl, int p)
{
    Nodo *nuovaTesta = (Nodo *)malloc(sizeof(Nodo));
    nuovaTesta->n = p;
    nuovaTesta->next = *pl;
    *pl = nuovaTesta;
}

void insCoda(Lista *pl, int p)
{
    Nodo *corrente = *pl;
    Nodo *nuovaCoda = (Nodo *)malloc(sizeof(Nodo));
    nuovaCoda->n = p;
    nuovaCoda->next = NULL;

    if (corrente == NULL)
    {
        *pl = nuovaCoda;
    }
    else
    {
        while (corrente->next != NULL)
        {
            corrente = corrente->next;
        }

        corrente->next = nuovaCoda;
    }
}

void elimTesta(Lista *pl)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    *pl = (*pl)->next;
    free(aux);
}

void stampa(Lista l)
{
    int lunghezza;

    while (l)
    {
        printf("%d ", (l->n));
        l = l->next;
    }
    printf("\n");
}

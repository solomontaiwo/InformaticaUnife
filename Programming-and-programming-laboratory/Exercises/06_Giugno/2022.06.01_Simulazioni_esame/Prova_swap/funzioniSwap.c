#include <stdio.h>
#include <stdlib.h>

#include "funzioniSwap.h"

void nuovaLista(Lista *pl)
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

void insTesta(Lista *pl, Dato d)
{
    Nodo *nuovaLista = (Nodo *)malloc(sizeof(Nodo));
    nuovaLista->d = d;
    nuovaLista->next = *pl;
    *pl = nuovaLista;
}

int elimTesta(Lista *pl)
{
    Nodo *aux = *pl;
    *pl = (*pl)->next;
    free(aux);
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

int contaLista(Lista l)
{
    int conta = 0;
    while (l)
    {
        conta++;
        l = l->next;
    }
    return conta;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
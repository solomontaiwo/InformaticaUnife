// implementazione sequenziale ADT lista
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void nuovaLista(Lista *pl)
{
    pl->n_elementi = 0;
}

int piena(Lista l)
{
    return l.n_elementi == DIM;
}

int lunghezza(Lista l)
{
    return l.n_elementi;
}

void insOrd(Lista *pl, int numero)
{
    int i;
    if (piena(*pl))
    {
        printf("Lista piena\n");
        exit(-1);
    }
    i = pl->n_elementi;
    while (i > 0 && pl->dati[i - 1] > numero)
    {
        pl->dati[i] = pl->dati[i - 1];
        i--;
    }
    pl->dati[i] = numero;
    pl->n_elementi++;
}

void stampa(Lista l)
{
    int i;
    for (i = 0; i < l.n_elementi; i++)
    {
        printf("%d ", l.dati[i]);
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

void inizializzaLista(Lista *pl)
{
    pl->n_elementi = 0;
}

int lunghezza(Lista l)
{
    return l.n_elementi;
}

int listaPiena(Lista l)
{
    return l.n_elementi == DIMENSIONI;
}

void insOrd(Lista *pl, int numero)
{
    if (listaPiena(*pl))
    {
        printf("La lista e' piena.\n");
        exit(-1);
    }
    else
    {
        int i = pl->n_elementi;
        while (i > 0 && pl->dati[i - 1] > numero)
        {
            pl->dati[i] = pl->dati[i - 1];
            i--;
        }
        pl->dati[i] = numero;
        pl->n_elementi++;
    }
}

void stampa(Lista l)
{
    for (int i = 0; i < l.n_elementi; i++)
    {
        printf("%d ", l.dati[i]);
    }
    puts("");
}
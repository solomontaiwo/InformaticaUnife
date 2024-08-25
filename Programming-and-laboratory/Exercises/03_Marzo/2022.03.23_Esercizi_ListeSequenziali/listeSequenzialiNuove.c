#include <stdio.h>
#include <stdlib.h>
#include "listeSequenzialiNuove.h"

void inizializza(Lista *pl)
{
    pl->numeroElementi = 0;
}

int vuota(Lista l)
{
    return l.numeroElementi == 0;
}

int piena(Lista l)
{
    return l.numeroElementi == SIZE;
}

int ricerca(Lista l, int numero)
{
    for (int i = 0; i < l.numeroElementi; i++)
    {
        if (l.dati[i] == numero)
            return 1;
    }
    return 0;
}

void insTesta(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("Impossibile inserire elemento in lista piena.\n");
        exit(-1);
    }
    else
    {
        int i = pl->numeroElementi;
        for (i; i > 0; i--)
        {
            pl->dati[i] = pl->dati[i - 1];
        }
        pl->dati[0] = numero;
        pl->numeroElementi++;
    }
}

void insOrd(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("Impossibile inserire nuovo elemento in lista piena.\n");
        exit(-1);
    }
    else
    {
        int i = pl->numeroElementi;
        while (i > 0 && pl->dati[i - 1] > numero)
        {
            pl->dati[i] = pl->dati[i - 1];
            i--;
        }
        pl->dati[i] = numero;
        pl->numeroElementi++;
    }
}

void stampa(Lista l)
{
    int i = 0;
    while (i < l.numeroElementi)
    {
        printf("%d ", l.dati[i]);
        i++;
    }
    puts("");
}

void elimElemento1(Lista *pl, int numero)
{
    for (int i = 0; i < pl->numeroElementi; i++)
    {
        if (pl->dati[i] == numero)
        {
            for (int j = i; j < pl->numeroElementi - 1; i++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->numeroElementi--;
            return;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "listeSequenziali.h"

void inizializzaLista(Lista *pl)
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

void stampa(Lista l)
{
    for (int i = 0; i < l.numeroElementi; i++)
        printf("%d ", l.dati[i]);
    puts("");
}

int lunghezza(Lista l)
{
    return l.numeroElementi;
}

void insOrd(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("Impossibile aggiungere elementi a lista piena.\n");
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

void elim1(Lista *pl, int numero)
{
    for (int i = 0; i < pl->numeroElementi; i++)
    {
        if (pl->dati[i] == numero)
        {
            for (int j = i; j < pl->numeroElementi - 1; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->numeroElementi--;
            return;
        }
    }
}

void elimTutti(Lista *pl, int numero)
{
    int i = pl->numeroElementi;
    while (pl->numeroElementi > 0)
    {
        if (pl->dati[i] == numero)
        {
            for (int j = i; j < pl->numeroElementi - 1; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->numeroElementi--;
        }
        else
            i++;
    }
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
        printf("Impossibile inserire elementi in lista piena.\n");
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
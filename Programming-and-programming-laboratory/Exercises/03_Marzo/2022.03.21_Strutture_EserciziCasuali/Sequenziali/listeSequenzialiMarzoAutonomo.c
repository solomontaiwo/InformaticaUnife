#include "listeSequenzialiMarzoAutonomo.h"
#include <stdio.h>
#include <stdlib.h>

void nuovaLista(Lista *pl)
{
    pl->numeroElementi = 0;
}

int piena(Lista l)
{
    return l.numeroElementi == SIZE;
}

int vuota(Lista l)
{
    return l.numeroElementi == 0;
}

int ricerca(Lista l, int numero)
{
    for (int i = 0; i < l.numeroElementi; i++)
    {
        if (l.dati[i] == numero)
            return 1;
        else
            i++;
    }
}

void insOrd(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("Impossibile inserire nuovo elemento perche' la lista e' piena.\n");
        exit(-1);
    }
    int i = pl->numeroElementi;
    while (i > 0 && pl->dati[i - 1] > numero)
    {
        pl->dati[i] = pl->dati[i - 1];
        i--;
    }
    pl->dati[i] = numero;
    pl->numeroElementi++;
}

void insTesta(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("Impossibile aggiungere elemento alla lista in quanto piena.\n");
        exit(-1);
    }
    
    int i = pl->numeroElementi;
    for (i; i > 0; i--)
    {
        pl->dati[i] = pl->dati[i - 1];
    }
    pl->dati[0] == numero;
    pl->numeroElementi++;
}

void elim1(Lista *pl, int numero)
{
    for (int i = 0; i < pl->numeroElementi; i++)
    {
        if (pl->dati[i] == numero)
        {
            int j;
            for (j = i; j < pl->numeroElementi; j++)
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
    for (int i = 0; i < pl->numeroElementi; i++)
    {
        if (pl->dati[i] == numero)
        {
            int j;
            for (j = i; j < pl->numeroElementi; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->numeroElementi--;
        }
    }
}

void stampa(Lista l)
{
    for (int i = 0; i < l.numeroElementi; i++)
        printf("%d ", l.dati[i]);
    puts("");
}
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct
{
    int n_elementi;
    int dato[SIZE];
} Lista;

void inizializza(Lista *pl)
{
    pl->n_elementi = 0;
}

int vuota(Lista l)
{
    return l.n_elementi == 0;
}

int piena(Lista l)
{
    return l.n_elementi == SIZE;
}

void stampa(Lista l)
{
    for (int i = 0; i < l.n_elementi; i++)
        printf("%d ", l.dato[i]);
    puts("");
}

void insOrd(Lista *pl, int numero)
{
    int i = pl->n_elementi;
    while (i > 0 && pl->dato[i - 1] > numero)
    {
        pl->dato[i] = pl->dato[i - 1];
        i--;
    }
    pl->dato[i] = numero;
    pl->n_elementi++;
}

void insTesta(Lista *pl, int numero)
{
    for (int i = pl->n_elementi; i > 0; i--)
    {
        pl->dato[i] = pl->dato[i - 1];
    }
    pl->dato[0] = numero;
    pl->n_elementi++;
}

void elim1(Lista *pl, int numero)
{
    for (int i = 0; i < pl->n_elementi; i++)
    {
        if (pl->dato[i] == numero)
        {
            for (int j = i; j < pl->n_elementi - 1; j++)
            {
                pl->dato[j] = pl->dato[j + 1];
            }
            pl->n_elementi--;
            return;
        }
    }
}

void elimTutti(Lista *pl, int numero)
{
    for (int i = 0; i < pl->n_elementi; i++)
    {
        if (pl->dato[i] == numero)
        {
            for (int j = i; j < pl->n_elementi - 1; j++)
            {
                pl->dato[j] = pl->dato[j + 1];
            }
            pl->n_elementi--;
        }
    }
}

int ricerca(Lista l, int numero)
{
    int i = 0;
    while (i < l.n_elementi)
    {
        if (l.dato[i] == numero)
        {
            return 1;
        }
        else
            i++;
    }
    return 0;
}
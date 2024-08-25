#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct
{
    int n_elementi;
    int dati[SIZE];
} Lista;

void inizializza(Lista *pl)
{
    pl->n_elementi == 0;
}

int vuota(Lista l)
{
    return l.n_elementi == 0;
}

int piena(Lista l)
{
    return l.n_elementi == SIZE;
}

void insTesta(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("La lista e' piena.\n");
        exit(-1);
    }

    int i = pl->n_elementi;
    for (i; i > 0; i--)
    {
        pl->dati[i] = pl->dati[i - 1];
    }
    pl->dati[0] == numero;
    pl->n_elementi++;
}

void insOrd(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("La lista e' piena.\n");
        exit(-1);
    }

    int i = pl->n_elementi;
    while (i > 0 && pl->dati[i - 1] > numero)
    {
        pl->dati[i] = pl->dati[i - 1];
        i--;
    }
    pl->dati[i] = numero;
    pl->n_elementi++;
}

void elimina1(Lista *pl, int numero)
{
    int i;
    for (i = 0; i < pl->n_elementi; i++)
    {
        if (pl->dati[i] == numero)
        {
            for (int j = i; j < pl->n_elementi; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->n_elementi--;
            return;
        }
    }
}

void eliminaTutti(Lista *pl, int numero)
{
    for (int i = 0; i < pl->n_elementi; i++)
    {
        if (pl->dati[i] == numero)
        {
            for (int j = i; j < pl->n_elementi; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->n_elementi--;
        }
    }
}

int stampa(Lista l)
{
    for (int i = 0; i < l.n_elementi; i++)
        printf("%d ", l.dati[i]);
    puts("");
}

int lunghezza(Lista l)
{
    return l.n_elementi;
}

int ricerca(Lista *pl, int numero)
{
    int i;
    while (i < pl->n_elementi)
    {
        if (pl->dati[i] == numero)
        {
            return 1;
        }
        else
            i++;
    }
}
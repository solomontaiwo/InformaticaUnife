#include <stdio.h>
#include <stdlib.h>
#define DIMENSIONE 100

typedef struct
{
    int n_elementi;
    int dati[DIMENSIONE];
} Lista;

void nuovaLista(Lista *pl)
{
    pl->n_elementi = 0;
}
int vuota(Lista l)
{
    return l.n_elementi == 0;
}

int piena(Lista l)
{
    return l.n_elementi == DIMENSIONE;
}
void insTesta(Lista *pl, int numero)
{
    int i;
    if (piena(*pl))
    {
        printf("La lista e' piena.\n");
        exit(1);
    }

    for (i = pl->n_elementi; i > 0; i--)
    {
        pl->dati[i] = pl->dati[i - 1];
    }
    pl->dati[0] = numero;
    pl->n_elementi++;
}
void insOrd(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("La lista e' piena.\n");
        exit(1);
    }

    for (int i = pl->n_elementi; i > 0; i--)
    {
        while (i > 0 && pl->dati[i - 1] > numero)
        {
            pl->dati[i] = pl->dati[i - 1];
            i--;
        }
        pl->dati[i] = numero;
        pl->n_elementi++;
    }
}
int ricerca(Lista l, int numero)
{
    for (int i = l.n_elementi; i > 0; i--)
    {
        if (l.dati[i] == numero)
            return i;
    }
    return 0;
}
void elim1(Lista *pl, int numero)
{
    int i = 0;
    while (i < pl->n_elementi)
    {
        if (pl->dati[i] == numero)
        {
            int j;
            for (j = i; j < pl->n_elementi - 1; j++)
                pl->dati[j] = pl->dati[j + 1];
            pl->n_elementi--;
            return;
        }
        else
            i++;
    }
}
void elimTutti(Lista *pl, int numero)
{
    int i = 0;
    while (i < pl->n_elementi)
    {
        if (pl->dati[i] == numero)
        {
            int j;
            for (j = i; j < pl->n_elementi - 1; j++)
                pl->dati[j] = pl->dati[j + 1];
            pl->n_elementi--;
        }
        else
            i++;
    }
}
int lunghezza(Lista l)
{
    return l.n_elementi;
}
void stampa(Lista l)
{
    int i;
    for (i = 0; i < l.n_elementi; i++)
        printf("%d ", l.dati[i]);
}
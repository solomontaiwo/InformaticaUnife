#include <stdio.h>
#include "lista.h"

void inizializzaLista(Lista *pl)
{
    pl->n_elementi = 0;
}

int listaPiena(Lista l)
{
    return l.n_elementi == DIM;
}

int listaVuota(Lista l)
{
    return l.n_elementi == 0;
}

int lunghezza(Lista l)
{
    return l.n_elementi;
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

void insTesta(Lista *pl, int numero)
{
    if (listaPiena(*pl))
    {
        printf("La lista e' piena.\n");
        exit(-1);
    }
    else
    {
        for (int i = pl->n_elementi; i > 0; i--)
        {
            pl->dati[i] = pl->dati[i - 1];
        }
        pl->dati[0] = numero;
        pl->n_elementi++;
    }
}

void stampa(Lista l)
{
    for (int i = 0; i < l.n_elementi; i++)
        printf("%d ", l.dati[i]);
    puts("");
}

int ricerca(Lista l, int numero)
{
    for (int i = 0; i < l.n_elementi; i++)
    {
        if (numero == l.dati[i])
            return 1;
    }
    return -1;
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
            {
                pl->dati[j] = pl->dati[j + 1];
            }
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
            for (j = i; pl->n_elementi - 1; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->n_elementi--;
        }
        else
            i++;
    }
}

void elim1(Lista *pl, int numero)
{
    int i = 0;
    while (i < pl->n_elementi)
    {
        if (pl->dati[i] == numero)
        {
            int j;
            for (j = i; pl->n_elementi - 1; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->n_elementi--;
        }
        else
            i++;
    }
}

void insOrd(Lista *pl, int numero)
{
    if (listaPiena(*pl))
    {
        printf("Lista piena.\n");
        exit(-1);
    }
    int i = pl->n_elementi;
    while (i > 0 && pl->dati[i - 1] > numero)
    {
        pl->dati[i] = pl->dati[i - 1];
        i--;
    }
    pl->dati[i] = numero;
    pl->n_elementi;
}

void elim1(Lista *pl, int numero)
{
    int i = 0;
    while (i < pl->n_elementi)
    {
        if (pl->dati[i] == numero)
        {
            int j;
            for (j = i; pl->n_elementi - 1; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->n_elementi--;
            return;
        }
        else
            i++;
    }
}

void insOrd(Lista *pl, int numero)
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

void eliminazioneSingolo(Lista *pl, int numero)
{
    int i = 0;
    while (i < pl->n_elementi)
    {
        if (pl->dati[i] == numero)
        {
            int j;
            for (j = i; pl->n_elementi - 1; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->n_elementi--;
            return;
        }
        else
            i++;
    }
}

int ricerca(Lista l, int numero)
{
    int i = 0;
    while (i < l.n_elementi)
    {
        if (l.dati[i] == numero)
        {
            return 1;
        }
        else
            i++;
    }
    return 0;
}

void elimTutti(Lista *pl, int numero)
{
    int i;
    while (i < pl->n_elementi)
    {
        if (pl->dati[i] == numero)
        {
            int j;
            for (j = i; pl->n_elementi - 1; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->n_elementi--;
        }
        else
            i++;
    }
}

void insTesta(Lista *pl, int numero)
{
    if (listaPiena(*pl))
    {
        printf("La lista e' piena.\n");
        exit(-1);
    }
    else
    {
        int i = pl->n_elementi;
        for (i; i > 0; i--)
        {
            pl->dati[i] = pl->dati[i + 1];
        }
        pl->dati[0] = numero;
        pl->n_elementi++;
    }
}

int ricerca(Lista l, int numero)
{
    int i;
    for (i = 0; i < l.n_elementi; i++)
    {
        if (l.dati[i] == numero)
        {
            return 1;
        }
        return 0;
    }
}

void elim1(Lista *pl, int numero)
{
    int i = 0;
    while (i < pl->n_elementi)
    {
        if (pl->dati[i] == numero)
        {
            int j;
            for (int j = i; pl->n_elementi - 1; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->n_elementi--;
            return;
        }
        else
            i++;
    }
}

void insTesta(Lista *pl, int numero)
{
    // verificare se lista e' piena

    int i = pl->n_elementi;
    for (i; i > 0; i--)
    {
        pl->dati[i] = pl->dati[i - 1];
    }
    pl->dati[0] = numero;
    pl->n_elementi++;
}

void elimTutti(Lista *pl, int numero)
{
    int i = 0;
    while (i < pl->n_elementi)
    {
        if (pl->dati[i] == numero)
        {
            int j;
            for (j = i; pl->n_elementi - 1; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->n_elementi--;
        }
        else
            i++;
    }
}

void ricerca(Lista l, int numero)
{
    int i;
    for (i = 0; i < l.n_elementi; i++)
    {
        if (l.dati[i] == numero)
            return 1;
    }
    return 0;
}

void insOrd(Lista *pl, int numero)
{
    // verifica se lista e' piena //

    int i = pl->n_elementi;
    while (i > 0 && pl->dati[i - 1] > numero)
    {
        pl->dati[i] = pl->dati[i - 1];
        i--;
    }
    pl->dati[i] = numero;
    pl->n_elementi++;
}

void insTesta(Lista *pl, int numero)
{
    for (int i = pl->n_elementi; i > 0; i--)
    {
        pl->dati[i] = pl->dati[i - 1];
    }
    pl->dati[0] = numero;
    pl->n_elementi++;
}

int ricerca(Lista l, int numero)
{
    int i;
    for (i = 0; i < l.n_elementi; i++)
    {
        if (l.dati[i] == numero)
        {
            return 1;
        }
    }
    return 0;
}

void insTesta(Lista *pl, int numero)
{
    for (int i = pl->n_elementi; i > 0; i--)
    {
        pl->dati[i] = pl->dati[i - 1];
    }
    pl->dati[0] = numero;
    pl->n_elementi++;
}

void insOrd(Lista *pl, int numero)
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

void elim1(Lista *pl, int numero)
{
    int i = 0;
    while (i < pl->n_elementi)
    {
        if (pl->dati[i] == numero)
        {
            int j;
            for (j = i; pl->n_elementi - 1; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->n_elementi--;
            return;
        }
        else
            i++;
    }
}

int ricerca(Lista l, int numero)
{
    int i;
    for (i = 0; i < l.n_elementi; i++)
    {
        if (l.dati[i] == numero)
            return 1;
    }
    return 0;
}

void insTesta(Lista *pl, int numero)
{
    if (listaPiena(*pl))
    {
        printf("La lista e' piena\n");
        exit(-1);
    }
    else
    {
        for (int i = pl->n_elementi; i > 0; i--)
        {
            pl->dati[i] = pl->dati[i - 1];
        }
        pl->dati[0] = numero;
        pl->n_elementi++;
    }
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

void eliminazioneSingola(Lista *pl, int numero)
{
    int i;
    for (i = 0; i < pl->n_elementi; i++)
    {
        if (pl->dati[i] == numero)
        {
            int j;
            for (j = i; pl->n_elementi - 1; j++)
            {
                pl->dati[j] = pl->dati[j + 1];
            }
            pl->n_elementi--;
            return;
        }
    }
}
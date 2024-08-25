#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// lista sequenziale

typedef struct
{
    int n_elementi;
    int dati[SIZE];
} Lista;

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
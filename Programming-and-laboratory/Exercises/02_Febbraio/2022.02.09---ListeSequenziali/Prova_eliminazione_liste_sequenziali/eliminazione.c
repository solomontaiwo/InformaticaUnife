#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct
{
    int n_elementi;
    int dati[SIZE];
} Lista;

int piena(Lista l);
void inizializza(Lista *pl);
void elim1(Lista *pl, int numero);
void eliminazioneSingola(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
int stampa(Lista l);

int main(int argc, char *argv[])
{
    Lista listone;

    inizializza(&listone);

    for (int i = 0; i < SIZE; i++)
        insOrd(&listone, i);

    stampa(listone);

    elim1(&listone, 3);

    stampa(listone);
}

int piena(Lista l)
{
    return l.n_elementi == SIZE;
}

void inizializza(Lista *pl)
{
    pl->n_elementi = 0;
}

void elim1(Lista *pl, int numero) // prima casistica
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

void eliminazioneSingola(Lista *pl, int numero) // seconda casistica
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

int stampa(Lista l)
{
    for (int i = 0; i < l.n_elementi; i++)
        printf("%d ", l.dati[i]);
    puts("");
}
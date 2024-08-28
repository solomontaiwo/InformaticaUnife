// Il seguente programma richiede all’utente DIM numeri interi e li salva in un array; dopo di che stampa l’indice dell’array contenente l’intero massimo. //
#include <stdio.h>
#define SIZE 5

int main()
{
    int array[SIZE], i, massimo = 0, dl;

    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &array[i]);
    }

    for (i = 0; i < SIZE; i++)
    {
        if (array[i] > massimo)
        {
            massimo = array[i];
            dl = i;
        }
    }
    printf("L'indice dell'array contentente l'intero massimo (%d) e' pari a %d.\n", massimo, dl);
}
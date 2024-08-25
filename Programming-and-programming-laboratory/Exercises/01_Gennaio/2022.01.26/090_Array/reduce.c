// Scrivere un programma che richieda all’utente 5 numeri, e poi stampi una riga contenente l’uguaglianza fra l’espressione prodotto dei cinque numeri inseriti e il risultato della moltiplicazione. Ad esempio: 2 x 4 x 5 x 3 x 2 = 240 //
#include <stdio.h>
#define SIZE 5

int main()
{
    int array[SIZE], prodotto = 1, i;

    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &array[i]);
    }

    for (i = 0; i < SIZE; i++)
    {
        prodotto = prodotto * array[i];
    }

    for (i = 0; i < SIZE - 1; i++)
    {
        printf("%d x ", array[i]);
    }

    printf("%d = %d\n", array[SIZE - 1], prodotto);
}
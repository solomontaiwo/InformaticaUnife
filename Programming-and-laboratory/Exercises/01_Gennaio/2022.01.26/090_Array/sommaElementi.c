// Il seguente programma salva DIM numeri richiesti all’utente in un array, e poi ne stampa una somma. //
#include <stdio.h>
#define DIM 5

int main()
{
    int array[DIM], somma = 0, dl = 0;

    for (int i = 0; i < DIM; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < DIM; i++)
    {
        dl = dl + array[i];
    }

    printf("%d\n", dl);
}
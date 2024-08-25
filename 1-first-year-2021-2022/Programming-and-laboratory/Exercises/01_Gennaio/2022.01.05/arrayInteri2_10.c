#include <stdio.h>
#define DIM 5 // dimensione array, senza ";"

int array[DIM];
int i;
int main(void)
{
    for (int i = 0; i < DIM; i++)
    {
        array[i] = 2 + 2 * i;
        // printf("%d\n", array[i]);
    }
    printf("%s%20s\n", "Elemento", "Valore");

    for (int i = 0; i < DIM; i++)
    {
        printf("%d%26d\n", i, array[i]);
    }
}
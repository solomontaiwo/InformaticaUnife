#include <stdio.h>
#define DIM 10

int main(void)
{
    int array[DIM] = {9, 3, 4, 6, 1, 5, 2, 8, 7, 10};

    printf("Array con ordine iniziale sparso: ");
    for (int i = 0; i < DIM; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Array ordinato: ");
    for (int passaggio = 0; passaggio < DIM; passaggio++)
    {
        for (int i = 0; i < DIM; i++)
        {
            if (array[i] > array[i + 1])
            {
                int fermo = array[i];
                array[i] = array[i + 1];
                array[i + 1] = fermo;
            }
        }
    }
    for (int i = 0; i < DIM; i++)
    {
        printf("%d ", array[i]);
    }
}

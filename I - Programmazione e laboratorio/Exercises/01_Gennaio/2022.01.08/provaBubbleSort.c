#include <stdio.h>

int main(void)
{
    int array[5] = {55, 47, 99, 1, 32};

    printf("Stampa array con ordine iniziale: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
    }

    for (int passaggio = 0; passaggio < 5; passaggio++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (array[i] > array[i + 1])
            {
                int fermo = array[i];
                array[i] = array[i + 1];
                array[i + 1] = fermo;
            }
        }
    }
    printf("\nStampa con array ordinato: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
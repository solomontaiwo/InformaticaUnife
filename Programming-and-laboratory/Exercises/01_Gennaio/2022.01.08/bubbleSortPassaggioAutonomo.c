#include <stdio.h>
#define SIZE 10

void bubbleSort(int *const array, size_t size);

int main(void)
{
    int array[SIZE] = {1, 4, 2, 3, 10, 9, 7, 6, 5, 8};

    printf("Stampa array con ordine iniziale: ");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }

    bubbleSort(array, SIZE);

    printf("\nStampa con array ordinato: ");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int *const array, size_t size)
{
    void swap(int *elemento1ptr, int *elemento2ptr);

    for (int passaggio = 0; passaggio < SIZE - 1; passaggio++)
    {
        for (size_t i = 0; i < SIZE - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
            }
        }
    }
}

void swap(int *elemento1ptr, int *elemento2ptr)
{
    int fermo = *elemento1ptr;
    *elemento1ptr = *elemento2ptr;
    *elemento2ptr = fermo;
}

#include <stdio.h>
#define SIZE 10

void bubbleSort(int *const array, size_t size); // prototipo di funzione bubbleSort

int main(void)
{

    int a[SIZE] = {2, 6, 4, 6, 10, 12, 89, 68, 45, 37};

    printf("Elementi array in ordine originario: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }

    bubbleSort(a, SIZE);

    printf("\nElementi array in ordine ascendente: ");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

void bubbleSort(int *const array, size_t size)
{
    void swap(int *element1Ptr, int *element2Ptr); // prototipo di funzione swap con indirizzi di riferimento

    for (int passaggio = 0; passaggio < SIZE; passaggio++)
    {

        for (int i = 0; i < SIZE; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
            }
        }
    }
}

void swap(int *element1Ptr, int *element2Ptr)
{
    int fermo = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = fermo;
}
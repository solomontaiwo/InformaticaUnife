#include <stdio.h>
#define SIZE 20

void selectionSort(size_t array[], size_t lunghezza);
void swap(size_t array[], size_t primo, size_t secondo);

int main(void)
{

    size_t array[SIZE] = {44, 634, 2321, 5, 22, 7, 113, 4, 8, 57467, 12, 0, 777, 234, 673, 1, 43, 76, 888, 32};

    printf("Array iniziale, disordinato: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%ld ", array[i]);
    }
    puts("");

    selectionSort(array, SIZE);

    printf("Array finale, ordinato: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%ld ", array[i]);
    }
    puts("");
}

void selectionSort(size_t array[], size_t lunghezza)
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        int piccolo = i;
        for (int j = i + 1; j < SIZE; j++)
        {
            if (array[i] > array[j])
            {
                piccolo = j;
                swap(array, i, piccolo);
            }
        }
    }
}

void swap(size_t array[], size_t primo, size_t secondo)
{
    if (array[primo] > array[secondo])
    {
        int temp = array[primo];
        array[primo] = array[secondo];
        array[secondo] = temp;
    }
}

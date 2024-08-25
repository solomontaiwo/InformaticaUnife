#include <stdio.h>
#define SIZE 5

void swap(int array[], size_t primo, size_t secondo);
void selectionSort(int array[], int lunghezza);

int main()
{
    int array[SIZE] = {9, 8, 1, 6, 11}, i, j;

    printf("Questo e' l'array iniziale, non ordinato: ");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }

    selectionSort(array, SIZE);

    printf("\nQuesto e' l'array finale, ordinato: ");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    puts("");
}

void selectionSort(int array[], int lunghezza)
{
    for (int i = 0; i < SIZE; i++)
    {
        int piccolo = i;

        for (int j = i + 1; j < SIZE; j++)
        {
            if (array[j] < array[piccolo])
            {
                piccolo = j;
            }
        }
        swap(array, i, piccolo);
    }
}

void swap(int array[], size_t primo, size_t secondo)
{
    int temp = array[primo];
    array[primo] = array[secondo];
    array[secondo] = temp;
}
#include <stdio.h>
#define SIZE 20

void insertionSort(int array[], size_t lunghezza);

int main(void)
{
    int array[SIZE] = {9, 2, 4, 15, 7, 11, 20, 18, 19, 17, 6, 8, 1, 3, 12, 16, 5, 10, 13, 14};

    printf("Array iniziale: ");
    for (int i = 0; i < SIZE - 1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("%d.\n", array[SIZE - 1]);

    insertionSort(array, SIZE);

    printf("Array finale: ");
    for (int i = 0; i < SIZE - 1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("%d.\n", array[SIZE - 1]);
}

void insertionSort(int array[], size_t lunghezza)
{
    for (int i = 0; i < SIZE; i++)
    {
        int posizioneElemento = i;
        int elementoDaInserire = array[i];

        while (posizioneElemento > 0 && array[posizioneElemento - 1] > elementoDaInserire)
        {
            if (array[posizioneElemento - 1] > array[posizioneElemento])
            {
                array[posizioneElemento] = array[posizioneElemento - 1];
                posizioneElemento--;
            }
            array[posizioneElemento] = elementoDaInserire;
        }
    }
}
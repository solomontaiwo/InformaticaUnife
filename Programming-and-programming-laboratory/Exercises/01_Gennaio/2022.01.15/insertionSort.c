#include <stdio.h>
#define SIZE 10

void insertionSort(int array[], size_t lunghezza);

int main(void)
{
    int array[SIZE] = {10, 2, 7, 3, 9, 8, 1, 6, 4, 5};

    printf("Array iniziale, non ordinato: ");
    for (int i = 0; i < SIZE - 1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("%d.\n", array[SIZE - 1]);

    insertionSort(array, SIZE);

    printf("Array finale, ordinato: ");
    for (int i = 0; i < SIZE - 1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("%d.\n", array[SIZE - 1]);
}

void insertionSort(int array[], size_t lunghezza)
{
    for (size_t i = 1; i < SIZE; i++)
    {
        size_t posizioneElemento = i; // posizione in cui inserire elemento
        int inserimento = array[i];   // contiene l'elemento da inserire

        while (posizioneElemento > 0 && array[posizioneElemento - 1] > inserimento)
        { // sposta l'elemento a destra di una posizione
            array[posizioneElemento] = array[posizioneElemento - 1];
            --posizioneElemento;
        }
        array[posizioneElemento] = inserimento; // inserisce l'elemento al suo posto
    }
}
#include <stdio.h>
#define SIZE 10

void insertionSort(int array[], int lunghezza);

int main()
{
    int array[SIZE] = {10, 8, 1, 6, 7, 2, 5, 3, 4, 9};

    insertionSort(array, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    puts("");
}

void insertionSort(int array[], int lunghezza)
{
    for (int i = 1; i < lunghezza; i++)
    {
        int posizioneElemento = i;
        int inserimento = array[i];

        while (posizioneElemento > 0 && array[posizioneElemento - 1] > inserimento)
        {
            array[posizioneElemento] = array[posizioneElemento - 1];
            posizioneElemento--;
        }
        array[posizioneElemento] = inserimento;
    }
}
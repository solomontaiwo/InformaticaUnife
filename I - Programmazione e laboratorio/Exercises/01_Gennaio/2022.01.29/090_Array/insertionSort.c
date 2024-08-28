#include <stdio.h>
#define SIZE 5

void insertionSort(int array[], int lunghezza);

int main(void)
{
    int numeri[SIZE] = {99, 100, 1, 6, 8}, i;

    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", numeri[i]);
    }

    puts("");

    insertionSort(numeri, SIZE);

    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", numeri[i]);
    }

    puts("");
}

void insertionSort(int array[], int lunghezza)
{
    for (int i = 1; i < SIZE; i++)
    {
        int posizioneElemento = i;
        int elemento = array[i];

        while (posizioneElemento > 0 && array[posizioneElemento - 1] > elemento)
        {
            array[posizioneElemento] = array[posizioneElemento - 1];
            posizioneElemento--;
        }
        array[posizioneElemento] = elemento;
    }
}
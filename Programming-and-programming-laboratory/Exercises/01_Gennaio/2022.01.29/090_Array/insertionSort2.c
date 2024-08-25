#include <stdio.h>
#define SIZE 5

void insertionSort(float array[], int lunghezza);

int i;

int main()
{

    float voti[SIZE] = {2.5, 10.6, 8.4, 4.7, 6.1};

    for (i = 0; i < SIZE; i++)
    {
        printf("%.1f ", voti[i]);
    }

    puts("");

    insertionSort(voti, SIZE);

    for (i = 0; i < SIZE; i++)
    {
        printf("%.1f ", voti[i]);
    }

    puts("");
}

void insertionSort(float array[], int lunghezza)
{
    for (i = 1; i < lunghezza; i++)
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
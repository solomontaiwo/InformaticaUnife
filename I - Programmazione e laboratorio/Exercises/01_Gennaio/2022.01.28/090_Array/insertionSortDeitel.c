#include <stdio.h>
#define SIZE 5

void insertionSort(int array[], int lunghezza);

int main()
{
    int valori[SIZE] = {10, 2, 5, 9, 3};

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", valori[i]);
    }
    puts("");

    insertionSort(valori, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", valori[i]);
    }
    puts("");
}

void insertionSort(int array[], int lunghezza)
{
    for (int i = 1; i < SIZE; i++)
    {
        int posizioneInserimento = i;
        int elemento = array[i];

        while (posizioneInserimento > 0 && array[posizioneInserimento - 1] > elemento)
        {
            array[posizioneInserimento] = array[posizioneInserimento - 1];
            posizioneInserimento--;
        }
        array[posizioneInserimento] = elemento;
    }
}
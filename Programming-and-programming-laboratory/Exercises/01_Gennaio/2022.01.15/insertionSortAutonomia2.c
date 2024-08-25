#include <stdio.h>
#define SIZE 10

void insertionSort(int array[], size_t lunghezza); // prototipo di funzione

int main(void)
{

    int array[SIZE] = {10, 3, 5, 6, 7, 8, 4, 9, 2, 1};

    printf("Array iniziale, disordinato: ");
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

    for (int i = 0; i < SIZE; i++)
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

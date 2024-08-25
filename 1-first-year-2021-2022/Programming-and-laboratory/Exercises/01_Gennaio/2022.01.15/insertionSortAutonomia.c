#include <stdio.h>
#define SIZE 10

void insertionSort(int array[], size_t lenght);

int main(void)
{

    int array[SIZE] = {18, 16, 20, 17, 19, 10, 13, 15, 11, 12};

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

void insertionSort(int array[], size_t lenght)
{

    for (int i = 1; i < SIZE; i++)
    {
        int posizioneCorrente = i;
        int elementoDaInserire = array[i];

        while (posizioneCorrente > 0 && array[posizioneCorrente - 1] > elementoDaInserire)
        {
            array[posizioneCorrente] = array[posizioneCorrente - 1];
            posizioneCorrente--;
        }

        array[posizioneCorrente] = elementoDaInserire;
    }
}
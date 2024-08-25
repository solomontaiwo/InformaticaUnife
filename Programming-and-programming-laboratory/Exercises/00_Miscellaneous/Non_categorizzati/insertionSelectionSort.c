#include <stdio.h>
#define SIZE 5

void selectionSort(int array[], int lunghezza);
void insertionSort(int array[], int lunghezza);
void swap(int array[], int primoValore, int secondoValore);

int main(void)
{
    int valori1[SIZE] = {5, 7, 0, 2, 8}, valori2[SIZE] = {11, 19, 16, 18, 15};

    printf("Primo array di valori non ordinato: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", valori1[i]);
    puts("");

    printf("Secondo array di valori non ordinato: ");
    for (int k = 0; k < SIZE; k++)
        printf("%d ", valori2[k]);
    printf("\n\n");

    selectionSort(valori1, SIZE);

    printf("Primo array di valori ordinato: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", valori1[i]);
    puts("");

    insertionSort(valori2, SIZE);

    printf("Secondo array di valori ordinato: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", valori2[i]);
    puts("");
}

void selectionSort(int array[], int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
    {
        int piccolo = i;
        for (int j = i + 1; j < lunghezza; j++)
        {
            if (array[j] < array[piccolo])
            {
                piccolo = j;
            }
        }
        swap(array, i, piccolo);
    }
}

void swap(int array[], int primoValore, int secondoValore)
{
    int temp = array[primoValore];
    array[primoValore] = array[secondoValore];
    array[secondoValore] = temp;
}

void insertionSort(int array[], int lunghezza)
{
    for (int i = 1; i < lunghezza; i++)
    {
        int posizioneElemento = i;
        int elemento = array[i];
        {
            while (posizioneElemento > 0 && array[posizioneElemento - 1] > elemento)
            {
                array[posizioneElemento] = array[posizioneElemento - 1];
                posizioneElemento--;
            }
            array[posizioneElemento] = elemento;
        }
    }
}
#include <stdio.h>
#define SIZE 5

void swap(int array[], int primoElemento, int secondoElemento);

void selectionSort(int array[], int lunghezza);

int main()
{
    int valori[SIZE] = {1, 9, 8, 3, 5};

    for (int i = 0; i < SIZE; i++)
        printf("%d ", valori[i]);
    puts("");

    selectionSort(valori, SIZE);

    for (int i = 0; i < SIZE; i++)
        printf("%d ", valori[i]);
    puts("");
}

void swap(int array[], int primoElemento, int secondoElemento)
{
    int temp = array[primoElemento];
    array[primoElemento] = array[secondoElemento];
    array[secondoElemento] = temp;
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
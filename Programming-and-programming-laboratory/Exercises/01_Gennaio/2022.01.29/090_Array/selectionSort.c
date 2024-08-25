#include <stdio.h>
#define SIZE 5

void selectionSort(int array[], int lunghezza);
void swap(int array[], int primoValore, int secondoValore);

int main()
{

    int posizioni[SIZE] = {10, 8, 9, 3, 1};

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", posizioni[i]);
    }

    puts("");

    selectionSort(posizioni, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", posizioni[i]);
    }

    puts("");
}

void selectionSort(int array[], int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
    {
        int piccolo = i;
        for (int j = i + 1; j < SIZE; j++)
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
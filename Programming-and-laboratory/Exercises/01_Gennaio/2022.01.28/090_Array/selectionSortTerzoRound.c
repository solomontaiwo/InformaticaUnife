#include <stdio.h>
#define SIZE 10

void selectionSort(int arrray[], int lunghezza);
void swap(int array[], int primoElemento, int secondoElemento);

int main()
{
    int posizioni[SIZE] = {10, 8, 5, 7, 3, 1, 6, 4, 0, 2};
    puts("Array disordinato:");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", posizioni[i]);
    }

    puts("");

    selectionSort(posizioni, SIZE);

    puts("Array ordinato:");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", posizioni[i]);
    }

    puts("");
}

void selectionSort(int array[], int lunghezza)
{
    for (int i = 0; i < SIZE; i++)
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

void swap(int array[], int primoElemento, int secondoElemento)
{
    int temp = array[primoElemento];
    array[primoElemento] = array[secondoElemento];
    array[secondoElemento] = temp;
}
#include <stdio.h>
#define SIZE 5

void selectionSort(int array[], int lunghezza);
void swap(int array[], int primo, int secondo);

int i;

int main()
{
    int numeriCasuali[SIZE] = {1, 10, 8, 3, 5};

    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", numeriCasuali[i]);
    }

    puts("");

    selectionSort(numeriCasuali, SIZE);

    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", numeriCasuali[i]);
    }

    puts("");
}

void selectionSort(int array[], int lunghezza)
{
    for (i = 0; i < SIZE; i++)
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

void swap(int array[], int primo, int secondo)
{
    int temp = array[primo];
    array[primo] = array[secondo];
    array[secondo] = temp;
}
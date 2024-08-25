#include <stdio.h>
#define SIZE 5

void selectionSort(int array[], int lunghezza);
void swap(int array[], int primo, int secondo);

int main()
{
    int numeri[SIZE] = {8, 9, 1, 4, 10};

    puts("Array in disordine:");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", numeri[i]);
    }

    puts("");

    selectionSort(numeri, SIZE);

    puts("Array in ordine:");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", numeri[i]);
    }

    puts("");
}

void selectionSort(int array[], int lunghezza)
{
    for (int i = 0; i < SIZE; i++)
    {
        int piuPiccolo = i;
        for (int j = i + 1; j < SIZE; j++)
        {
            if (array[j] < array[piuPiccolo])
            {
                piuPiccolo = j;
            }
        }
        swap(array, i, piuPiccolo);
    }
}

void swap(int array[], int primo, int secondo)
{
    int temp = array[primo];
    array[primo] = array[secondo];
    array[secondo] = temp;
}
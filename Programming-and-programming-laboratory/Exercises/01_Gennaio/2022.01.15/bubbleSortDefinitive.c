#include <stdio.h>
#define SIZE 20

void bubbleSort(int array[], size_t lunghezza);
void swap(int array[], int primo, int secondo);

int main(void)
{

    int array[SIZE] = {9, 2, 4, 15, 7, 11, 20, 18, 19, 17, 6, 8, 1, 3, 12, 16, 5, 10, 13, 14};

    printf("Array non ordinato: ");
    for (int i = 0; i < SIZE - 1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("%d.\n", array[SIZE - 1]);

    bubbleSort(array, SIZE);

    printf("Array ordinato: ");
    for (int i = 0; i < SIZE - 1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("%d.\n", array[SIZE - 1]);
}

void bubbleSort(int array[], size_t lunghezza)
{
    for (int passaggio = 0; passaggio < SIZE - 1; passaggio++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (array[i] > array[i + 1])
                swap(array, i, i + 1);
        }
    }
}

void swap(int array[], int primo, int secondo)
{
    int temp = array[primo];
    array[primo] = array[secondo];
    array[secondo] = temp;
}
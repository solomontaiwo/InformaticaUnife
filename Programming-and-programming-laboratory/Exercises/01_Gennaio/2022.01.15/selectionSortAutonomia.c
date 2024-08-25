#include <stdio.h>
#define SIZE 10

void selectionSort(int array[], int lenght);
void swap(int array[], int primo, int secondo);

int main(void)
{

    int array[SIZE] = {8, 4, 9, 10, 1, 2, 6, 3, 7, 5};

    printf("Array iniziale: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    puts("");

    selectionSort(array, SIZE);

    printf("Array ordinato: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    puts("");
}

void selectionSort(int array[], int lenght)
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        int piccolo = i;
        for (int j = i + 1; j < lenght; j++)
        {
            if (array[j] < array[i])
            {
                piccolo = j;
                swap(array, i, piccolo);
            }
        }
    }
}

void swap(int array[], int primo, int secondo)
{
    int temp = array[primo];
    array[primo] = array[secondo];
    array[secondo] = temp;
}
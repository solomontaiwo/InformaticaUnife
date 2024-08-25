#include <stdio.h>
#define SIZE 20

void bubbleSort(int array[], size_t lunghezza);
void swap(int array[], int primo, int secondo);

int main(void)
{
    int array[SIZE] = {665, 4, 2, 7456, 1231, 7665, 1232131, 643, 44, 754, 124213, 5464, 634, 13, 74, 8, 21, 543, 88, 0};

    printf("Array iniziale, disordinato: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    puts("");

    bubbleSort(array, SIZE);

    printf("Array finale, ordinato: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    puts("");
}

void bubbleSort(int array[], size_t lunghezza)
{
    for (int passaggio = 0; passaggio < SIZE - 1; passaggio++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(array, i, i + 1);
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
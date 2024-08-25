#include <stdio.h>
#define SIZE 10

void bubbleSort(int array[], size_t lenght)
{
    for (int passaggio = 0; passaggio < SIZE - 1; passaggio++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}
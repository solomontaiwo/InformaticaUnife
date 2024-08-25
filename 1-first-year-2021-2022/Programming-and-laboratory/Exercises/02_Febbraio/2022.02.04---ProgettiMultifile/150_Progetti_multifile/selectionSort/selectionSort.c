#include "swap.h"

void selectionSort(int array[], int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
    {
        int piccolo = i;
        {
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
}
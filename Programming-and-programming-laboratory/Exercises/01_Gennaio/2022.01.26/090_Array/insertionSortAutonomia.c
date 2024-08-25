#include <stdio.h>
#define SIZE 5

int main(void)
{
    int array[SIZE] = {55, 2, 66, 1, 8}, key, j, i;

    for (i = 0; i < SIZE; i++)
    {
        key = array[i];
        j = i - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    for (i = 0; i < SIZE; i++)
        printf("%d ", array[i]);
}
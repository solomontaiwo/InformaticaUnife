#include <stdio.h>
#define SIZE 10

int main()
{
    int array[] = {10, 8, 1, 6, 7, 2, 5, 3, 4, 9};

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
        int temp = array[i];
        array[i] = array[piccolo];
        array[piccolo] = temp;
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    puts("");
}
#include <stdio.h>
#define nElementi 10

int array[nElementi] = {99, 484, 24, 55, 33, 52, 1, 3, 56, 234};

int main(void)
{
    for (int i = 0; i < nElementi; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    for (int passaggi = 0; passaggi < nElementi; passaggi++)
    {
        for (int i = 0; i < nElementi; i++)
        {
            if (array[i] > array[i + 1])
            {
                int fermo = array[i];
                array[i] = array[i + 1];
                array[i + 1] = fermo;
            }
        }
    }
    for (int i = 0; i < nElementi; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
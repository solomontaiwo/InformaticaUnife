#include <stdio.h>
#include "selectionSort.h"
#define SIZE 10

int main(void)
{
    int numeri[SIZE] = {5, 9, 3, 4, 1, 10, 2, 7, 8, 6};

    printf("Array iniziale: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numeri[i]);

    puts("");

    selectionSort(numeri, SIZE);

    printf("Array ordinato: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numeri[i]);

    puts("");

    return 0;
}
#include <stdio.h>
#include "insertionSort.h"
#define SIZE 5

int main(void)
{
    int numeri[SIZE] = {4, 2, 7, 3, 1};

    puts("Valori iniziali, non ordinati:");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numeri[i]);
    puts("");

    insertionSort(numeri, SIZE);

    puts("Valori ordinati:");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numeri[i]);
    puts("");
}
#include <stdio.h>
#include "insertionSort.h"
#define SIZE 5

int main(void)
{
    int valori[SIZE] = {8, 54, 3, 0, 6};

    printf("Valori ordinati all'interno dell'array 'valori': ");

    insertionSort(valori, SIZE);

    for (int i = 0; i < SIZE; i++)
        printf("%d ", valori[i]);

    puts("");
}
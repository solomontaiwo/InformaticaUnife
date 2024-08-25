#include <stdio.h>
#include "selectionSort.h"
#define SIZE 5

int main(void)
{
    int valori[SIZE] = {8, 9, 7, 1, 5};

    printf("Valori ordinati all'interno dell'array 'valori': ");

    selectionSort(valori, SIZE);

    for (int i = 0; i < SIZE; i++)
        printf("%d ", valori[i]);

    puts("");
}
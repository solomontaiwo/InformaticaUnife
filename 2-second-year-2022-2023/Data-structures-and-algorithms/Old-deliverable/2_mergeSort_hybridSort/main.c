#include <stdio.h>
#include "insertionSort_mergeSort_hybridSort.h"

int main()
{
    int arr[] = {7, 34, 2, 74, 10, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array originale:\n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Array ordinato:\n");
    printArray(arr, size);

    return 0;
}
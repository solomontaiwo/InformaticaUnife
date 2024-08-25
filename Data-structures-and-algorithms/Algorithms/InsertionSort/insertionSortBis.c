#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int size)
{
    int key, i, j;
    for (j = 1; j < size; j++)
    {
        key = arr[j];
        i = j - 1;
        while ((i >= 0) && (arr[i] > key))
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int array[] = {5, 9, 1, 5, 3, 4};
    int dim = sizeof(array) / sizeof(array[0]);

    printf("Original array: \n");

    printArray(array, dim);

    insertionSort(array, dim);

    printf("Sorted array: \n");

    printArray(array, dim);

    return 0;
}
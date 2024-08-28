#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort(int arr[], int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0... i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char **argv)
{
    int array[] = {1, 2, 5, 2, 5, 7, 3};

    int n = sizeof(array) / sizeof(array[0]);

    printf("Original array: \n");

    printArray(array, n);

    insertionSort(array, n);

    printf("Sorted array: \n");

    printArray(array, n);

    return 0;
}
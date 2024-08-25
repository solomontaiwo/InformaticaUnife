#include <stdio.h>
#include <stdlib.h>

void swapValue(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the index of the pivot
int partition(int arr[], int p, int r)
{
    int x = arr[r]; // Choosing the last element as the pivot
    int i = p - 1;  // Index of the smaller element

    for (int j = p; j <= r - 1; j++)
    {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= x)
        {
            i++;
            swapValue(&arr[i], &arr[j]);
        }
    }
    // Swap the pivot element with the element at (i + 1), so that the pivot is
    // at its final sorted position
    swapValue(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        // Partition the array and get the pivot index
        int q = partition(arr, p, r);

        // Recursively sort the sub-arrays on either side of the pivot
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char **argv)
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements in an array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the index of the pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Swap the pivot element with the element at (i + 1),
    // so that the pivot is at its final sorted position
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to randomly choose a pivot and partition the array
int randomPartition(int arr[], int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);
    swap(&arr[randomIndex], &arr[high]); // Swap the randomly chosen element with the last element
    return partition(arr, low, high);    // Call the partition function
}

// Function to implement Randomized QuickSort
void randomizedQuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Randomly choose a pivot and get the pivot index
        int pivotIndex = randomPartition(arr, low, high);

        // Recursively sort the sub-arrays on either side of the pivot
        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    srand(time(NULL)); // Seed for the random number generator

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    randomizedQuickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

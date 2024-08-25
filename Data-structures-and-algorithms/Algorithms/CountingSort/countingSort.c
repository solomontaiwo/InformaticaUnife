#include <stdio.h>
#include <stdlib.h>

// Function to perform counting sort on arr[] based on the place value (exp)
void countingSort(int arr[], int output[], int n, int exp)
{
    const int base = 10; // Base of the numbering system

    int count[base] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % base]++;
    }

    // Update count[i] to store the actual position of the digit in output[]
    for (int i = 1; i < base; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % base] - 1] = arr[i];
        count[(arr[i] / exp) % base]--;
    }

    // Copy the output array to arr[], so that arr[] contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// Function to perform radix sort on arr[]
void radixSort(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Perform counting sort for every digit place
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        int *output = (int *)malloc(n * sizeof(int));
        countingSort(arr, output, n, exp);
        free(output);
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
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

#include "Algorithms.h"

void InsertionSort(int array[], int length)
{
    int i, j;
    int key;
    for (j = 1; j < length; j++)
    {
        key = array[j];
        i = j - 1;
        while (i >= 0 && array[i] > key)
        {
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
    }
}

// Merges two sorted arrays
void Merge(int array[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    // int *L = (int*)malloc(n1 * sizeof(int));
    // int *R = (int*)malloc(n2 * sizeof(int));
    // if (L == NULL || R == NULL) {
    //   printf("allocation problem.\n");
    // exit(0);
    //}
    int L[n1];
    int R[n2];

    int i;
    int j;
    int k;
    for (i = 0; i < n1; i++)
        L[i] = array[p + i];

    for (j = 0; j < n2; j++)
        R[j] = array[q + j + 1];

    i = 0;
    j = 0;
    for (k = p; k <= r; k++)
        if (i < n1)
            if (j < n2)
                if (L[i] < R[j])
                    CopyFromL(&i, array, L, k);
                else
                    CopyFromR(&j, array, R, k);
            else
                CopyFromL(&i, array, L, k);
        else
            CopyFromR(&j, array, R, k);

    // free(L);
    // free(R);
}

// Recursively splits the array into halves, sorts them, and then
// merges them back together
void MergeSort(int array[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        MergeSort(array, p, q);
        MergeSort(array, q + 1, r);
        Merge(array, p, q, r);
    }
}

void HybridSort(int array[], int p, int r)
{
    int q;
    if (r - p + 1 > 185)
    { // after 185 elements sort with Merge Sort
        q = (p + r) / 2;
        MergeSort(array, p, q);
        MergeSort(array, q + 1, r);
        Merge(array, p, q, r);
    }
    else
        AdaptedInsertionSort(array, p, r);
}

// An optimized version of insertion sort: it shifts elements to
// the right only once to make space for the new element (instead of continuosly
// swapping elements). More efficient for partially sorted sections
void AdaptedInsertionSort(int array[], int p, int r)
{
    int i, j;
    int key;
    for (j = p; j < r; j++)
    {
        key = array[j];
        i = j - 1;
        while (i >= p && array[i] > key)
        {
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
    }
}

// Swaps values in an array
void SwapValue(int array[], int s, int r)
{
    int temp = array[s];
    array[s] = array[r];
    array[r] = temp;
}

// Similar to partition but chooses a random pivot
int RandomizedPartition(int array[], int p, int r)
{
    int s = (rand() % (r - p + 1)) + p;
    SwapValue(array, s, r);
    return Partition(array, p, r);
}

// Similar to Quicksort but chooses a random pivot element
void RandomizedQuickSort(int array[], int p, int r)
{
    int q = 0;
    if (p < r)
    {
        q = RandomizedPartition(array, p, r);
        RandomizedQuickSort(array, p, q - 1);
        RandomizedQuickSort(array, q + 1, r);
    }
}

// Partitions the array into two halves such that elements
// smaller than a pivot are on the left and elements larger are
// on the right
int Partition(int array[], int p, int r)
{
    int x = array[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
        if (array[j] <= x)
        {
            i++;
            SwapValue(array, i, j);
        }
    SwapValue(array, i + 1, r);
    return i + 1;
}

// Divide-and-conquer algorithm that recursively divides the array into smaller
// sub-arrays based on a chosen pivot element and then sorts those sub-array
void QuickSort(int array[], int p, int r)
{
    int q = 0;
    if (p < r)
    {
        q = Partition(array, p, r);
        QuickSort(array, p, q - 1);
        QuickSort(array, q + 1, r);
    }
}

// Finds the median of three values
int MedianOfThree(int array[], int i, int j, int k)
{

    if (array[i] > array[j])
    {
        if (array[j] >= array[k])
            return j;
        else if (array[i] < array[k])
            return i;
        else
            return k;
    }
    else
    {
        if (array[i] >= array[k])
            return i;
        else if (array[j] < array[k])
            return j;
        else
            return k;
    }
}

int MedianOfThreePartition(int array[], int p, int r)
{
    int s = MedianOfThree(array, p, r, (p + r) / 2);
    SwapValue(array, s, r);
    return Partition(array, p, r);
}

// Similar to QuickSort, but uses the median-of-three pivot selection method
void MedianOfThreeQuickSort(int array[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = MedianOfThreePartition(array, p, r);
        MedianOfThreeQuickSort(array, p, q - 1);
        MedianOfThreeQuickSort(array, q + 1, r);
    }
}

// This version removes tail recursion by using a while loop
void TailQuickSort(int array[], int p, int r)
{
    int q = 0;
    while (p < r)
    {
        q = Partition(array, p, r);
        TailQuickSort(array, p, q - 1);
        p = q + 1;
    }
}

// Optimizes the recursion call and uses a pseudo-optimal pivot
// selection strategy called "median of three"
void OptimalTailQuickSort(int array[], int p, int r)
{
    int k = 0;
    int q = 0;
    while (p < r)
    {
        if (r - p + 1 > 93)
        {
            q = MedianOfThreePartition(array, p, r);
            if (q < ((p + r) / 2))
            {
                OptimalTailQuickSort(array, p, q - 1);
                p = q + 1;
            }
            else
            {
                OptimalTailQuickSort(array, q + 1, r);
                r = q - 1;
            }
        }
        else
        {
            AdaptedInsertionSort(array, p, r);
            return;
        }
    }
}

// Copy elements from the left and right arrays during the merge step of MergeSort
void CopyFromL(int *i, int array[], int L[], int k)
{
    array[k] = L[*i];
    *i = *i + 1;
}

void CopyFromR(int *j, int array[], int R[], int k)
{
    array[k] = R[*j];
    *j = *j + 1;
}

// Generates an array of random integers
void GenerateRandomArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
        array[i] = rand();
}

// Checks if an array is ordered (antagonist function for testing purposes)
int isOrdered(int array[], int length)
{
    for (int i = 1; i < length; i++)
    {
        if (array[i - 1] > array[i])
            return 0; // isOrdered
    }
    return 1; // isNotOrdered
}

#include <stdio.h>

int recursiveBinarySearch(int arr[], int low, int high, int k)
{
    if (low >= high)
        return -1;

    int mid = (high + low) / 2;

    if (arr[mid] == k)
        return mid;

    if (arr[mid] < k)
        return recursiveBinarySearch(arr, mid + 1, high, k);

    if (arr[mid] > k)
        return recursiveBinarySearch(arr, low, mid - 1, k);
}

int main(int argc, char **argv)
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = recursiveBinarySearch(arr, 0, n - 1, target);

    if (result == -1)
        printf("Element %d is not present in the array\n", target);
    else
        printf("Element %d is present at index %d\n", target, result);

    return 0;
}
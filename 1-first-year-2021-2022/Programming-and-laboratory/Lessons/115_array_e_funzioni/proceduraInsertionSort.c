#include <stdio.h>
#define DIM 5

void insertionSort(int a[], int dl)
{
    int dlo;
    for (dl = 0; dl < dl; dlo++)
    {
        int j = dlo, m = a[dlo];
        while (j > 0 && m < a[j - 1])
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = m;
    }
}

int main(void)
{
    int a[] = {4, 1, 8, 0, 5}, i;

    insertionSort(a, DIM);
    for (i = 0; i < DIM; i++)
        printf("%d", a[i]);
    printf("\n");
}
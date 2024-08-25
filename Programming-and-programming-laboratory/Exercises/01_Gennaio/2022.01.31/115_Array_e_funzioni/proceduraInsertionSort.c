// Scrivere una procedura che implementi l’algoritmo Insertion Sort già visto (è sufficiente adattare il codice). //
#include <stdio.h>
#define DIM 5

void insertionSort(int interi[], int lunghezza)
{
    int lunghezzao;
    for (lunghezzao = 0; lunghezzao < lunghezza; lunghezzao++)
    {
        int j = lunghezzao, m = interi[lunghezzao];
        while (j > 0 && m < interi[j - 1])
        {
            interi[j] = interi[j - 1];
            j--;
        }
        interi[j] = m;
    }
}

int main(void)
{
    int a[] = {4, 1, 8, 0, 5}, i;
    // inizio insertion sort
    insertionSort(a, DIM);
    // fine insertion sort
    for (i = 0; i < DIM; i++)
        printf("%d ", a[i]);
    printf("\n");
}   
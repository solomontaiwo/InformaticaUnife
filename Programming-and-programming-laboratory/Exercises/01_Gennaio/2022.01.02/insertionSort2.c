#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 5 //lunghezza array

int main()
{
    int a[] = {8, 3, 5, 2, 4};
    int i, dl, m, j;

    for (dl = 0; dl < DIM; dl++)
    {
        int j = dl, m = a[dl];
        while (j > 0 && m < a[j - 1])
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = m;
    }
    for (i = 0; i < DIM; i++)
        printf("%d ", a[i]);
    printf("\n");
}
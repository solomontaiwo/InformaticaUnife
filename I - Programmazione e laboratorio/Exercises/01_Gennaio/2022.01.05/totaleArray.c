#include <stdio.h>
#define DIM 12

int array[DIM] = {1, 3, 5, 4, 7, 2, 99, 16, 45, 67, 89, 45};
int totale = 0;

int main()
{
    for (int i = 0; i < DIM; i++)
    {
        totale = totale + array[i];
    }
    printf("%d\n", totale);
}
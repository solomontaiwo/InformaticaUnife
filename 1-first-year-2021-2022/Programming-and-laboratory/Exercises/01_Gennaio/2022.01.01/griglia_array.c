#include <stdio.h>
#include <stdlib.h>

int griglia[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int i, j;

int main()
{
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("Elemento a [%d][%d]: %d\n", i, j, griglia[i][j]);
    }
}
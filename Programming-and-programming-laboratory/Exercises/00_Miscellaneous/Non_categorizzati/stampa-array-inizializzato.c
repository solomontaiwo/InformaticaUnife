#include <stdio.h>
#define DIM 5

int main(void)
{
    int i;
    int a[DIM] = {2, 4, 6, 1, 2};
    for (i = 0; i < DIM; i++)
        printf("%d\n", a[i]);
    return 0;
}

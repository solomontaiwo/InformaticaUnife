#include <stdio.h>

void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main(void)
{
    int a = 2, b = 3;

    printf("a = %d, b = %d.\n", a, b);

    swap(&a, &b);

    printf("a = %d, b = %d.\n", a, b);
}
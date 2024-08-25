#include <stdio.h>

int main()
{
    int x = 14;
    printf("x is %d\n", x);

    int *pointer = &x;

    printf("Pointer is %x\n", pointer);

    printf("x is %d\n", *pointer);

    *pointer = 21;

    printf("x is %d %d\n", x, *pointer);
}
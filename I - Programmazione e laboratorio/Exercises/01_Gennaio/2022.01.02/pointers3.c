#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 10;
    int *p;
    p = &a;

    printf("a = %d\n", a);
    *p = 12; // value at addressi pointed by p = 12 - dereferencing
    printf("a = %d\n", a);
}
#include <stdio.h>

void swap(int *pm, int *pn)
{
    int t = *pm;
    *pm = *pn;
    *pn = t;
}

void ordina2(int *pa, int *pb)
{
    if (*pa > *pb)
        swap(pa, pb);
}

int main()
{
    int a = 3, b = 2;
    ordina2(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}
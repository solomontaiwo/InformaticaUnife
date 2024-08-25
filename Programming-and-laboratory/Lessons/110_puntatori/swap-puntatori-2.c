#include <stdio.h>

void swap(int *pm, int *pn)
{
    int t;
    t = *pm;
    *pm = *pn;
    *pn = t;
}

int main()
{
    int a = 2, b = 3;
    swap(&a, &b);
    printf("%d %d\n", a, b); // stampa 3 2, input iniziale invertito
}
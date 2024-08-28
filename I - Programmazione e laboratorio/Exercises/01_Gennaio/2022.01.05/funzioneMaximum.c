#include <stdio.h>

int a, b, c;

int maximum(int a, int b, int c);

int main(void)
{
    printf("Immetti tre numeri interi, ti restituiro' quello con valore maggiore: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("Il valore piu' grande di questa serie e' pari a %d.\n", maximum(a, b, c));
}

int maximum(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    else if (b > a && b > c)
        return b;
    else
        return c;
}
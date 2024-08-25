#include <stdio.h>
#include <stdlib.h>

int potenza(int base, int esponente)
{
    int p = 1;
    int i;
    for (i = 1; i <= esponente; i++)
        p = p * base;
    return p;
};

int main()
{
    int a = 0;
    int b = 0;

    printf("Dammi due numeri interi, li usero' come base ed esponente di una potenza: \n");
    scanf("%d %d", &a, &b);

    printf("La potenza ottenuta da %d e %d e' %d\n", a, b, potenza(a, b));

    return 0;
}
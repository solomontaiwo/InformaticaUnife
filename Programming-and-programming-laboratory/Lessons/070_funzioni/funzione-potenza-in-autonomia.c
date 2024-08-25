#include <stdio.h>

int potenza(int base, int esp)
{
    int cont, prod = 1;
    for (cont = 0; cont < esp; cont++)
        prod *= base;

    return prod;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", potenza(a, b) - potenza(b, a));
    return 0;
}
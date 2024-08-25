#include <stdio.h>

int main(void)
{
    int a, b, somma;
    int *ptr1, *ptr2;

    printf("Inserisci il primo numero: ");
    scanf("%d", &a);

    printf("Inserisci il secondo numero: ");
    scanf("%d", &b);

    ptr1 = &a;
    ptr2 = &b;

    somma = *ptr1 + *ptr2;

    printf("la somma dei numeri inseriti e ' pari a %d.\n", somma);

    return 0;
}
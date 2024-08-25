#include <stdio.h>
#include "swap.h"

int swap(int *a, int *b);

int main(int argc, char *argv[])
{
    int numero1, numero2;

    printf("Inserisci due numeri: ");

    scanf("%d %d", &numero1, &numero2);

    printf("Numeri prima dello swap: %d %d\n", numero1, numero2);

    swap(&numero1, &numero2);

    printf("Numeri dopo lo swap: %d %d\n", numero1, numero2);
}
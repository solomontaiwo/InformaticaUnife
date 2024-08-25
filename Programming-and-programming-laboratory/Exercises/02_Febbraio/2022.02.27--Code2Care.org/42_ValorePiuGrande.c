#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero1, numero2, numero3;
    int maggiore;

    printf("Inserisci tre numeri interi: ");
    scanf("%d %d %d", &numero1, &numero2, &numero3);

    maggiore = numero1;

    if (maggiore < numero2)
        maggiore = numero2;

    if (maggiore < numero3)
        maggiore = numero3;

    printf("%d\n", maggiore);
}
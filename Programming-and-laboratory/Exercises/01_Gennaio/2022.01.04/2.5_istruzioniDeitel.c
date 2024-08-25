// Questo programma calcola il prodotto di tre numeri interi

#include <stdio.h>

int x, y, z, result;

int main(void)
{
    printf("Inserisci tre numeri interi: ");
    scanf("%d %d %d", &x, &y, &z);

    result = x * y * z;

    printf("Il prodotto e' %d.\n", result);
}
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero1, numero2, divisione;

    printf("Inserisci due numeri interi: ");
    scanf("%d %d", &numero1, &numero2);

    divisione = numero1 / numero2;

    printf("La divisione tra i due numero e' pari a %d.\n", divisione);
}
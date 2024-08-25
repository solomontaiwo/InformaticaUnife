#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero1, numero2;
    int differenza;

    printf("Inserisci due numeri interi: ");
    scanf("%d %d", &numero1, &numero2);

    differenza = numero1 - numero2;

    printf("La differenza tra i due valori e' pari a %d.\n", differenza);
}
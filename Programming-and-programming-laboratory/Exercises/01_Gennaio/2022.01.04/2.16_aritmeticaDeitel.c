// Questo programma stampa la somma, il prodotto, la diffenza, il quozient ed il resto di due numeri interi

#include <stdio.h>

int a, b;

int main(void)
{
    printf("Inserisci due numeri interi: ");
    scanf("%d %d", &a, &b);
    printf("Somma %d.\n", a + b);
    printf("Differenza %d.\n", a - b);
    printf("Quoziente %d.\n", a / b);
    printf("Resto %d.\n", a % b);
}
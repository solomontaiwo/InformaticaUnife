#include <stdio.h>

int main()
{
    printf("Questo programma stampa il prodotto di tre interi.\n\nInserisci tre numeri interi: ");

    int x, y, z, risultato;

    scanf("%d%d%d", &x, &y, &z);

    risultato = x + y + z;

    printf("\nLa somma dei valori da te inseriti e' pari a %d.\n", risultato);
}

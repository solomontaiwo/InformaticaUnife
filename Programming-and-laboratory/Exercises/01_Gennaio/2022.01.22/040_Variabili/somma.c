/* Calcolare la somma di tre numeri richiesti all’utente. */

#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Inserisci tre valori, ne calcolero' la somma: ");
    scanf("%d%d%d", &a, &b, &c);

    printf("%d + %d + %d = %d\n", a, b, c, a + b + c);
}
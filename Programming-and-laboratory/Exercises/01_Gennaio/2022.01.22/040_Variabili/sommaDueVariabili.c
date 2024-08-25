/* Calcolare la somma di due numeri richiesti all’utente. */

#include <stdio.h>

int main()
{
    int a, b;

    printf("Inserisci due valori, ne calcolero' la somma: ");
    scanf("%d%d", &a, &b);

    printf("%d + %d = %d\n", a, b, a + b);
}
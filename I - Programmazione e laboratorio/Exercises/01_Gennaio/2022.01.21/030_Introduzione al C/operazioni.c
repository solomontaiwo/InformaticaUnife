/* Scrivere un programma che stampi a video la somma, la differenza, il prodotto e il
quoziente intero dei due numeri interi 5 e 2. Verificarne la correttezza compilandolo ed
eseguendolo. */

#include <stdio.h>

int main()
{
    float a = 5, b = 2;

    printf("%.f + %.f = %.f\n", a, b, a + b);
    printf("%.f + %.f = %.f\n", a, b, a - b);
    printf("%.f + %.f = %.f\n", a, b, a * b);
    printf("%.f + %.f = %.1f\n", a, b, a / b);
}

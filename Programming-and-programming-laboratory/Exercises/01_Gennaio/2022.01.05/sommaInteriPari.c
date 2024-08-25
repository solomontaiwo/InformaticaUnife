#include <stdio.h>

int somma = 0;

int main()
{
    for (int numero = 2; numero <= 100; numero += 2)
    {
        somma = numero + somma;
    }
    printf("La somma dei numeri interi pari da 2 a 100 e' pari a %d.\n", somma);
}

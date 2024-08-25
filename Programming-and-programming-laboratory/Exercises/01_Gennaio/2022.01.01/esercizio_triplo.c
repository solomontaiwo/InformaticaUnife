// scrivere un programma che calcoli la somma dei tripli dei numeri interi dispari compresi fra 20 e 30 - hint: s1, s2, s3
#include <stdio.h>

int i = 20;
int j;
int acc = 0;

int main()
{
    for (i = 20; i <= 30; i++) // s1 - generazione sequenza
    {
        if (i % 2 == 1) // s2 - filter
        {
            j = 3 * i; // s3 - map

            acc = acc + j;
        }
    }
    printf("%d\n", acc);
}

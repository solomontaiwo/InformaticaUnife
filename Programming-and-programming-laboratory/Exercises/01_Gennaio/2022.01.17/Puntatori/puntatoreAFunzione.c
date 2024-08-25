#include <stdio.h>

double media(double a, double b)
{
    return (a + b) / 2;
}

int main()
{
    double (*mediaPtr)(double, double);
    mediaPtr = &media;

    double risultato = mediaPtr(5, 3);

    printf("Risultato: %.2f\n", risultato);
}
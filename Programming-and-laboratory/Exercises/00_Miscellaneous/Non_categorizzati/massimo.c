#include <stdio.h>

float massimo(float a, float b)
{
    if (a >= b)
        return a;
    else
        return b;
}

float main(float n)
{
    float a, b;
    printf("Dammi due valori, ti darò il valore massimo.\n");
    scanf("%f%f", &a, &b);
    printf("Il valore massimo di %.3f,%.3f è %.3f.\n", a, b, massimo(a, b));
}
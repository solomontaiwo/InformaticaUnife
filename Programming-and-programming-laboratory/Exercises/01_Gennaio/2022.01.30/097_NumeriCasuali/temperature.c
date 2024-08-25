// Scrivere un programma che simuli 10 rilevazioni di temperature comprese fra 15.0°C e 25.0°C. //
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Rilevazione di temperatura: %.1f\n", 15.0 + 10.0 * (double)rand() / RAND_MAX);
    }
}
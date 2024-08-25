// Voto casuale in float tra 18.0 e 30.0 per 6 tentativi //
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    for (i = 0; i < 6; i++)
        printf("Voto d'esame: %.1f\n", 18.00 + 12.00 * (double)rand() / RAND_MAX);
}
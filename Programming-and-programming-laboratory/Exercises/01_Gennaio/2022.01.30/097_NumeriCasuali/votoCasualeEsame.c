// Scrivere un programma che riporti per cinque volte un numero casuale, corrispondente al voto di esame compreso tra 18 e 30 //
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("Voto d'esame: %d\n", 18 + rand() % 13);
    }
}
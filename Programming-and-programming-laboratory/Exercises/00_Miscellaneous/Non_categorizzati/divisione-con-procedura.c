#include <stdio.h>

void divisione(int dividendo, int divisore, int *pquoz, int *presto)
{
    *pquoz = dividendo / divisore;
    *presto = dividendo % divisore;
}

int main()
{

    int quoz, resto;
    divisione(15, 6, &quoz, &resto);
    printf("%d %d\n", quoz, resto);
}
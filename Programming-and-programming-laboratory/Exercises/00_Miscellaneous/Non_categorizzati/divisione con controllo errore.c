#include <stdio.h>

void divisione(int dividendo, int divisore, int *pquoz, int *presto, int *pok)
{
    if (divisore != 0)
    {
        *pok = 1;
        *pquoz = dividendo / divisore;
        *presto = dividendo % divisore;
    }
    else
        *pok = 0;
}

int main()
{

    int quoz, resto;
    int ok;
    divisione(15, 7, &quoz, &resto, &ok);
    if (ok)
        printf("%d %d\n", quoz, resto);
    divisione(15, 0, &quoz, &resto, &ok);
    if (ok)
        printf("%d %d\n", quoz, resto);
}
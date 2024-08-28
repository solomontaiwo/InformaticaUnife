#include <stdio.h>

int somma(int a, int b)
{
    return (a + b);
}

int main()
{
    int (*sommaPtr)(int, int);
    sommaPtr = &somma;

    int risultato = sommaPtr(5, 3);

    printf("Risultato: %d\n", risultato);
}
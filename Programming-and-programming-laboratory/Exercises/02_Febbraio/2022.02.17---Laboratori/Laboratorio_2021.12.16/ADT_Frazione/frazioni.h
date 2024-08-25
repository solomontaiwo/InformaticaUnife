#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num; // se num > 0 segno +, se num < 0 segno -
    int den;
} Frazione;

int MCD(int a, int b);
int valAssoluto(int d);
Frazione frazione(int n, int d);
Frazione leggiFrazione(void);
Frazione somma(Frazione f1, Frazione f2);
void stampaFrazionaria(Frazione f);
void stampaDecimale(Frazione f);
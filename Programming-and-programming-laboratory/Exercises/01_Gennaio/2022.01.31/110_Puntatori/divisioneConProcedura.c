// Scrivere e testare una procedura di nome divisione che calcoli quoziente e resto di due espressioni intere. //
#include <stdio.h>

void divisione(int dividendo, int divisore, double *pquoziente, double *presto)
{
    *pquoziente = (dividendo / divisore);
    *presto = (dividendo % divisore);
}

int main(void)
{
    printf("Inserisci due valori, ti stampero' il loro quoziente ed resto: ");

    int valore1, valore2;
    double quoziente, resto;

    scanf("%d %d", &valore1, &valore2);

    divisione(valore1, valore2, &quoziente, &resto);

    printf("Quoziente: %.1f\nResto: %.f\n", quoziente, resto);
}
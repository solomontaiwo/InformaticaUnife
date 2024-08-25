// Modificare la soluzione all’esercizio divisioneConProcedura in modo che, se il divisore è 0, la procedura o funzione divisione non esegua i calcoli (che comporterebbero floating point exception). //
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

    if (valore2 == 0)
        printf("Il divisore e' pari a %d, quindi il calcolo non deve essere eseguito.\n", valore2);
    else
    {
        divisione(valore1, valore2, &quoziente, &resto);
        printf("Quoziente: %.1f\nResto: %.f\n", quoziente, resto);
    }
}
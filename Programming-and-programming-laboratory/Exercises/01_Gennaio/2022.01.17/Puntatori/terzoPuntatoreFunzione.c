#include <stdio.h>

float stipendio(float fisso, float variabile)
{
    return (fisso + variabile);
}

int main()
{
    printf("Inserisci due dati: il primo relativo alla quota fissa del tuo stipendio, il secondo riguardante la quota variabile (bonus, ferie liquidate, ecc.): ");

    float fisso, variabile;
    scanf("%f%f", &fisso, &variabile);

    float (*stipendioPtr)(float, float);
    stipendioPtr = &stipendio;

    float risultato = stipendioPtr(fisso, variabile);

    printf("Il tuo stipendio complessivo ammonta a %.2f.\n", risultato);
}
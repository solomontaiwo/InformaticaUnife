#include <stdio.h>

float denaro(int banconote, float monete)
{
    return banconote + monete;
}

int main()
{

    printf("Inserisci le banconote e monete a tua disposizione: ");

    int banconote;
    float monete;

    scanf("%d%f", &banconote, &monete);

    float (*denaroPtr)(int, float);
    denaroPtr = &denaro;

    float risultato = denaroPtr(banconote, monete);

    printf("Il denaro complessivo a tua disposizione e' pari a %.2f.\n", risultato);
}
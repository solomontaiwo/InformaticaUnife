#include <stdio.h>

float divisione(float a, float b)
{
    return a / b;
}

int main()
{
    puts("Questo programma calcola quante caramelle possono mangiarsi i presenti a testa, tra quelle disponibili.");

    int caramelle;
    int presenti;

    printf("Indica il numero di caramelle a vostra disposizione: ");
    scanf("%d", &caramelle);

    printf("In quanti siete? ");
    scanf("%d", &presenti);

    float (*divisionePtr)(float, float);
    divisionePtr = &divisione;

    float caramelleATesta = divisionePtr(caramelle, presenti);

    printf("Il numero di caramelle che potete mangiare a testa e' pari a %.3f\n", caramelleATesta);
}
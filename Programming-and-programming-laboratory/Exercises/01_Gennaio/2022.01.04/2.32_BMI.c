/* calcolatore del BMI che legge il peso e l'altezza dell'utente e calcola l'indice di massa corporea dell'utente */

#include <stdio.h>

int main(void)
{
    int peso;
    float altezza, BMI;

    printf("Benvenuto, questo programma calcola il tuo indice di massa corporea!\nInnanzituto, eccoti la tabella riportante i valori del BMI: \n\n");
    printf("VALORI del BMI\nSottopeso:   meno di 18.5\nNormale:   tra 18.5 e 24.9\nSovrappeso:   tra 25 e 29.9\nObeso:   30 o oltre\n\n");

    printf("Inserisci il tuo peso in kg: ");
    scanf("%d", &peso);
    printf("Inserisci la tua altezza in metri: ");
    scanf("%f", &altezza);

    BMI = peso / (altezza * altezza);

    printf("Il tuo BMI equivale a %.2f.\n", BMI);
}
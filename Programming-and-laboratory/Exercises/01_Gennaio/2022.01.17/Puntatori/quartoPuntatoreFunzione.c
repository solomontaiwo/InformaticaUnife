#include <stdio.h>

float media(float a, float b, float c)
{
    return (a + b + c) / 3;
}

int main()
{

    printf("Inserisci i tuoi ultimi tre voti, ti riportero' la media: ");

    float primo, secondo, terzo;

    scanf("%f%f%f", &primo, &secondo, &terzo);

    float (*mediaPtr)(float, float, float);
    mediaPtr = &media;

    float risultato = mediaPtr(primo, secondo, terzo);

    printf("La media dei tuoi ultimi tre voti e' pari a %.2f\n", risultato);
}
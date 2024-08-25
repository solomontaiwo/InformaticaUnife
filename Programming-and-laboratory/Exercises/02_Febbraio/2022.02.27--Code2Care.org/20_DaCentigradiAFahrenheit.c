#include <stdio.h>

int main(int argc, char *argv[])
{
    float centigradi, fahrenheit;

    printf("Inserisci i gradi centigradi: ");
    scanf("%f", &centigradi);

    fahrenheit = (1.8 * centigradi) + 32;

    printf("I gradi farenheit sono pari a %.2f\n", fahrenheit);
}
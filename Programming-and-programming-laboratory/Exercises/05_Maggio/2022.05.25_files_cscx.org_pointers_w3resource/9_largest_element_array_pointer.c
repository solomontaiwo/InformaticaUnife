#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float *array, max = 0;
    int numeroElementi, i;

    printf("Inserisci il numero totale di elementi (da 1 a 100): ");
    scanf("%d", &numeroElementi);

    array = malloc(numeroElementi * sizeof(float));

    for (i = 0; i < numeroElementi; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%f", (array + i));
    }

    puts("");

    puts("Elementi inseriti:");

    for (i = 0; i < numeroElementi; i++)
        printf("%.2f \n", *(array + i));

    for (i = 0; i < numeroElementi; i++)
    {
        if (*(array + i) > max)
            max = *(array + i);
    }

    printf("\nElemento piu' grande: %.2f\n", max);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define NRIGHE 10
#define NCOLONNE 15
#define PROBMINA 0.2

float rnd_float(float a, float b)
{
    return a + (float)rand() / RAND_MAX * (b - a);
}

typedef struct
{
    int minata;
} Casella;

void inizializza(Casella c[NRIGHE][NCOLONNE])
{
    int i, j;
    for (i = 0; i < NRIGHE; i++)
        for (j = 0; j < NCOLONNE; j++)
        {
            if (rnd_float(0.0, 1.0) < PROBMINA)
                c[i][j].minata = 1;
            else
                c[i][j].minata = 0;
        }
}

void stampa(Casella c[NRIGHE][NCOLONNE])
{
    for (int j = 0; j < 2 * NCOLONNE + 1; j++)
        printf("-");
    printf("\n");
    for (int i = 0; i < NRIGHE; i++)
    {
        for (int j = 0; j < NCOLONNE; j++)
        {
            printf("|");
            if (c[i][j].minata)
                printf("*");
            else
                printf(" ");
        }
        printf("|\n");
        for (int j = 0; j < 2 * NCOLONNE + 1; j++)
            printf("-");
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    Casella campo[NRIGHE][NCOLONNE];

    inizializza(campo);
    stampa(campo);
}
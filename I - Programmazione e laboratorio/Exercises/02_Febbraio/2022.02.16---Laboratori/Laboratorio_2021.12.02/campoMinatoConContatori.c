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

int get(Casella c[][NCOLONNE], int j, int i)
{
    if (i >= 0 && i <= NCOLONNE && j >= 0 && j <= NRIGHE)
        return c[i][j].minata;
    else
        return 0;
}

int minaPresente(Casella c[][NCOLONNE], int i, int j)
{
    if (i >= 0 && i <= NRIGHE && j >= 0 && j < NCOLONNE)
        return c[i][j].minata;
    else
        return 0;
}

int mine_adiacenti(Casella c[NRIGHE][NCOLONNE], int rg, int cl)
{
    int mine = 0;
    int i, j;

    for (i = rg - 1; i <= rg + 1; i++)
        for (j = cl - 1; j <= cl + 1; j++)
            if (i != rg || j != cl)
                mine += minaPresente(c, i, j);
    return mine;
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
            {
                int contatore = mine_adiacenti(c, i, j);
                if (contatore > 0)
                    printf("%d", contatore);
                else
                    printf(" ");
            }
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
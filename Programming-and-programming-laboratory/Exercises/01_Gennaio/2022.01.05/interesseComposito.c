#include <stdio.h>

float patrimonioIniziale = 1000;
float tassoAnnualeInteresse = 0.05;
int anno;
float patrimonioFinale;

int main()
{
    printf("Anno\tGiacenza\n");

    for (anno = 1; anno <= 10; anno++)
    {
        patrimonioFinale = patrimonioIniziale + (tassoAnnualeInteresse * patrimonioIniziale);
        printf("%d\t%.2f\n", anno, patrimonioFinale);
        patrimonioIniziale = patrimonioFinale;
    }
}
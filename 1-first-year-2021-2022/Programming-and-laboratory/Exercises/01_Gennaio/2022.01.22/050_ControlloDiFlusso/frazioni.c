// Leggere quattro numeri che rappresentano numeratore e denominatore di due frazioni e dire se le due frazioni rappresentano lo stesso numero. //

#include <stdio.h>

int main()
{
    printf("Inserisci quattro numeri interi, ti diro' se le loro frazioni rappresentano lo stesso numero.\n");

    int numeratore1, numeratore2, denominatore1, denominatore2;
    printf("Prima frazione: ");
    scanf("%d %d", numeratore1, denominatore1);

    puts("");

    float frazione1 = numeratore1 / denominatore1;

    printf("Seconda frazione: ");
    scanf("%d %d", numeratore2, denominatore2);

    float frazione2 = numeratore2 / denominatore2;

    puts("");

    if (frazione1 == frazione2)
    {
        printf("Le frazioni %d/%d e %d/%d rappresentano lo stesso numero (%.2f).\n", numeratore1, denominatore1, numeratore2, denominatore2, frazione1);
    }
    else
    {
        printf("Le frazioni %d/%d e %d/%d rappresentano un numero diverso (%.2f).\n", numeratore1, denominatore1, numeratore2, denominatore2, frazione2);
    }
}
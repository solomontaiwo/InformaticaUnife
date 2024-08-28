#include <stdio.h>
int somma(int *primoNumero, int *secondoNumero);

int main(void)
{
    int numero1, numero2, totale;

    printf("Inserisci il primo numero: ");
    scanf("%d", &numero1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &numero2);

    totale = somma(&numero1, &numero2);

    printf("La somma di %d e %d e' %d.\n", numero1, numero2, totale);

    return 0;
}

int somma(int *primoNumero, int *secondoNumero)
{
    int terzoNumero;
    terzoNumero = *primoNumero + *secondoNumero;
    return terzoNumero;
}
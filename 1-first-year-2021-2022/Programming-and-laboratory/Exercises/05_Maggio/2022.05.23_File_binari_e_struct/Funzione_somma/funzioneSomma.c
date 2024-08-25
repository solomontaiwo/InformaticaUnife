#include <stdio.h>

int somma(int a, int b);

int main(int argc, char *argv[])
{

    int numero1, numero2, totale;

    printf("Inserisci due numeri: ");
    scanf("%d %d", &numero1, &numero2);

    totale = somma(numero1, numero2);

    printf("La somma dei valori da te inseriti e' pari a %d.\n", totale);

    return 0;
}

int somma(int a, int b)
{
    int s;
    s = a + b;
    return s;
}
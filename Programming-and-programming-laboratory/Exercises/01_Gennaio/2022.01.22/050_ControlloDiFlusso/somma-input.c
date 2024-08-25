// Si scriva un programma che legga da tastiera 5 numeri interi e ne stampi la somma. //
#include <stdio.h>

int main()
{
    int a, somma = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Inserisci un valore: ");
        scanf("%d", &a);
        somma += a;
    }
    printf("\nLa somma dei valori da te inseriti e' pari a %d.\n", somma);
}
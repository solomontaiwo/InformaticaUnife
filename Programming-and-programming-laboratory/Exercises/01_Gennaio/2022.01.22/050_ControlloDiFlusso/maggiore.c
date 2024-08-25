// Scrivere un programma che richieda all’utente due numeri interi e stampi il maggiore dei due. //

#include <stdio.h>

int main()
{
    int a, b;

    printf("Inserisci due numeri interi, stampero' quello con valore maggiore: ");

    scanf("%d%d", &a, &b);

    if (a > b)
    {
        printf("%d e' il valore maggiore.\n", a);
    }
    else
    {
        printf("%d e' il valore maggiore.\n", b);
    }
}
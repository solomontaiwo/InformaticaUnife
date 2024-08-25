// Scrivere un programma che richieda all’utente tre numeri interi e stampi il maggiore dei tre. //

#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Inserisci tre numeri, ti diro' qual e' il piu' grande: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a > b && a > c)
    {
        printf("Il valore piu' grande e' %d.\n", a);
    }
    else if (b > a && b > c)
    {
        printf("Il valore piu' grande e' %d.\n", b);
    }
    else
    {
        printf("Il valore piu' grande e' %d.\n", c);
    }
}
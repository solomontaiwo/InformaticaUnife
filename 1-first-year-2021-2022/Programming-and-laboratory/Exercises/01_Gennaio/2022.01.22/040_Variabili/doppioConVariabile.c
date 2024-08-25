/* Scrivere un programma che
1 definisca una variabile intera di nome v;
2 richieda all’utente un valore per v;
3 stampi il doppio di v. */

#include <stdio.h>

int main()
{
    int v;

    printf("Inserisci un valore, lo raddoppiero': ");
    scanf("%d", &v);

    printf("Il doppio di %d e' %d.\n", v, v * 2);
}
// Questo programma legge un intero, determina e stampa se esso sia pari o dispari

#include <stdio.h>

int main(void)
{
    int valore;

    printf("Inserisci un numero intero, ti diro' se e' pari o dispari: ");
    scanf("%d", &valore);
    if (valore % 2 == 0)
        printf("%d e' pari.\n", valore);
    else
        printf("%d e' dispari.\n", valore);
}
/* Scrivere un programma che richieda all’utente un numero intero e stampi il messaggio “Dispari” se il numero è dispari. */

#include <stdio.h>

int main()
{
    int intero;
    printf("Inserisci un numero intero, se e' dispari te lo diro', altrimenti...\n");

    scanf("%d", &intero);
    if (intero % 2 != 0)
    {
        printf("%d e' dispari.\n", intero);
    }
    else
    {
        printf("%d non e' un numero dispari, baka.\n", intero);
    }
}
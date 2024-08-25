/* Scrivere un programma che richieda all’utente un numero intero e stampi il messaggio “Positivo” se il numero è maggiore di 0. */

#include <stdio.h>

int main()
{
    int intero;
    printf("Inserisci un numero intero, se e' positivo te le diro', altrimenti...\n");

    scanf("%d", &intero);
    if (intero > 0)
    {
        printf("%d e' positivo.\n", intero);
    }
    else
    {
        printf("%d non e' un numero positivo, baka.\n", intero);
    }
}
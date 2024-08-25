/*  Scrivere un programma che simuli la verifica di un PIN inserito dall’utente.
In particolare, il programma deve richiedere un numero all’utente; se il numero è
uguale a 44122, deve stampare il messaggio “Accesso consentito”, mentre in caso
contrario il messaggio “Accesso negato”. */

#include <stdio.h>

int main()
{
    int pin;

    printf("Inserisci il codice PIN corretto: ");
    scanf("%d", &pin);

    if (pin == 44122)
    {
        printf("Accesso consentito.\n");
    }
    else
    {
        printf("Accesso negato.\n");
    }
}
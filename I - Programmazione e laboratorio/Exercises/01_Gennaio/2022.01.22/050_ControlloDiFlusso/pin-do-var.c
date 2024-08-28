// Scrivere un programma che richieda all’utente un PIN al massimo tre volte. Se l’utente inserisce il PIN esatto (uguale a 44122) il programma deve stampare il messaggio "Accesso consentito"; se l’utente commette tre errori, deve stampare il messaggio "Accesso negato". //
#include <stdio.h>

int main()
{
    int PIN = 44122, PINInserito, tentativi = 0;

    do
    {
        tentativi++;
        printf("Inserisci il PIN, hai un massimo di tre tentativi: ");
        scanf("%d", &PINInserito);
    } while (tentativi < 3 && PINInserito != 44122);
    if (PINInserito == 44122 && tentativi <= 3)
    {
        printf("\nAccesso consentito.\n");
    }
    else
    {
        printf("\nAccesso negato.\n");
    }
}
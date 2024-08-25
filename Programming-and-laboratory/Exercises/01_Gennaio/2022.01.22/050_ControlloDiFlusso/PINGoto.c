// Scrivere un programma che richieda all’utente un PIN, ripetendo la richiesta finché l’utente non inserisce il PIN 44122, dopo di che stampare il messaggio "Accesso consentito". //

#include <stdio.h>

int PIN = 44122, PINInserito;

int main()
{
    printf("Inserisci il PIN per proseguire: ");
inserimentoPIN:
    scanf("%d", &PINInserito);
    if (PINInserito != PIN)
    {
        printf("Hai inserito un PIN errato, ritenta: ");
        goto inserimentoPIN;
    }
    else
    {
        printf("Accesso consentito.\n");
    }
}

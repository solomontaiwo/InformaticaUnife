// Fare in modo che il programma inizialmente chieda all’utente un PIN ed esegua le successive istruzioni solo se il PIN immesso è uguale a 44122. //

#include <stdio.h>

int main()
{
    int PIN = 44122;
    int PINInserito;

inserimentoPIN:
    printf("Inserisci il PIN per procedere con la scelta del contatto da chiamare: ");

    scanf("%d", &PINInserito);

    if (PINInserito == PIN)
    {
        puts("");
        puts("Chi vuoi chiamare?");
        printf("1. Solomon\n2. Pino\n");

        int scelta;
        puts("");
        scanf("%d", &scelta);

        if (scelta == 1)
        {
            puts("");
            printf("Chiamata di Solomon in corso...\n");
        }
        else if (scelta == 2)
        {
            puts("");
            printf("Chiamata di Pino in corso...\n");
        }
        else
        {
            puts("");
            printf("Hai inserito un numero identificativo errato, il programma terminera'...\n");
        }
    }
    else
    {
        puts("");
        puts("Hai inserito un PIN errato, riprova.");
        goto inserimentoPIN;
    }
}
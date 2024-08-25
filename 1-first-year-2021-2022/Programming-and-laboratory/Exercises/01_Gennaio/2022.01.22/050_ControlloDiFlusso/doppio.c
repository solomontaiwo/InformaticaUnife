// Scrivere un programma che richieda all’utente numeri interi. Per ogni numero intero inserito, scriva il doppio. Il programma deve fermarsi quando l’utente scrive un numero negativo. //
#include <stdio.h>

int valoreInserito = 0;

int main()
{
    printf("Inserisci un valore intero, te ne stampero' il doppio finche' non inserirai un valore negativo: ");

    do
    {
        scanf("%d", &valoreInserito);
        if (valoreInserito >= 0)
        {
            printf("Il doppio di %d e' %d.\n", valoreInserito, valoreInserito * 2);
        }
        else
            break;
    } while (valoreInserito >= 0);
}
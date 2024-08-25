// Scrivere un programma che richieda all'utente 5 numeri interi e stampi la somma dei soli numeri positivi inseriti. //
#include <stdio.h>

int main()
{
    int valore;
    int somma = 0;

    printf("Inserisci cinque numeri interi, ti mostrero' la somma dei numeri positivi inseriti.\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Inserisci un valore intero: ");
        scanf("%d", &valore);

        if (valore <= 0)
            continue;
        somma += valore;
    }
    printf("La somma dei valori interi positivi e' pari a %d.\n", somma);
}
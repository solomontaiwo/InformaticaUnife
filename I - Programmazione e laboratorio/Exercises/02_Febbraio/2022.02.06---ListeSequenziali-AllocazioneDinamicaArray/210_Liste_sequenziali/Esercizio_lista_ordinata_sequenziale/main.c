/* Scrivere un programma che richieda all’utente un massimo di 50 numeri positivi, fermandosi quando l’utente scrive un numero minore o uguale a 0, e stampi i numeri positivi inseriti in ordine crescente.
 */
#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int valore;

int main()
{

    Lista l;

    inizializzaLista(&l);

    printf("Inserisci un massimo di 50 valori, stampero' i numeri inseriti in ordine crescente:\n");
    scanf("%d", &valore);

    for (int i = 1; i < 10; i++)
    {
        if (valore <= 0)
        {
            printf("Hai inserito un numero minore o uguale a 0, il programma terminera' la propria esecuzione.\n");
            break;
        }
        else
        {
            insOrd(&l, valore);
            scanf("%d", &valore);
        }
    }
    stampa(l);
}
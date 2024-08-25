// Inserisci all'interno di una lista sequenziale dei valori che verranno stampati in ordine //
#include <stdio.h>
#include "lista.h"

int valore;

int main()
{
    int i;
    Lista l;

    inizializza(&l);

    printf("Inserisci dei numeri, valori uguali o negativi terminano il programma:\n");

    while (valore >= 0 && i < 10)
    {
        scanf("%d", &valore);
        insOrd(&l, valore);
        i++;
    }

    stampa(l);
}
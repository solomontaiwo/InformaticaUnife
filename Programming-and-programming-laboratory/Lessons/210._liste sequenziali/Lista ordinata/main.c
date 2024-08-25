// programma principale

#include "lista.h"
#include <stdio.h>

int main()
{
    Lista l;
    int numero;

    nuovaLista(&l);

    printf("Inserisci numeri interi (negativo o 0 termina)\n");

    do
    {
        scanf("%d", &numero);
        if (numero <= 0)
            break;
        insOrd(&l, numero);
    } while (lunghezza(l) < 50);

    stampa(l);
}
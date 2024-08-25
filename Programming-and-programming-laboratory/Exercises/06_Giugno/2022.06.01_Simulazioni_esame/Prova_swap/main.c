#include <stdio.h>
#include <stdlib.h>

#include "funzioniSwap.h"

int main(int argc, char *argv[])
{
    Lista s;
    int numero = 0;

    nuovaLista(&s);

    scanf("%d", &numero);

    while (numero >= 0)
    {
        insTesta(&s, numero);
        scanf("%d", &numero);
    }

    printf("Lista non ordinata: \n");
    stampa(s);

    return 0;
}
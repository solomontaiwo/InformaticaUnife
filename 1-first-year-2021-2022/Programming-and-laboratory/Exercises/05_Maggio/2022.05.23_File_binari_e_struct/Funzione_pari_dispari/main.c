#include <stdio.h>
#include "funzione_pari_dispari.h"

int main(int argc, char *argv[])
{
    int v;

    printf("Inserisci un numero: ");
    scanf("%d", &v);

    pariDispari(v);

    return 0;
}
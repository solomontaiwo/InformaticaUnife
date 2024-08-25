#include <stdio.h>
#include "lunghezza.h"

int main(int argc, char *argv[])
{
    Lista bellaLista;

    listaNonOrdinata(&bellaLista, 5);

    printf("I valori all'interno della lista sono: ");
    stampa(bellaLista);

    printf("La lunghezza della lista 'bellaLista' e' pari a %d.\n", lunghezza(bellaLista));
}
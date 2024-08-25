#include <stdio.h>
#include "funzioniLista.h"

int main(int argc, char *argv[])
{

    Lista ciao;

    listaNonOrdinata(&ciao, 5);

    printf("Ecco i valori all'interno della lista: ");
    stampa(ciao);

    printf("Il valore massimo all'interno della lista e' %d", massimo(ciao));

    puts("");
}
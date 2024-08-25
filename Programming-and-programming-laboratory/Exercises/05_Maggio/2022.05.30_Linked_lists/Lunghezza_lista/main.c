#include <stdio.h>

#include "lunghezza.h"

int main(int argc, char *argv[])
{
    Lista conteggio;

    generaLista(&conteggio);

    stampa(conteggio);

    int lunghezzaLista = lunghezza(conteggio);

    printf("La lista ha %d elementi.\n", lunghezzaLista);

    return 0;
}
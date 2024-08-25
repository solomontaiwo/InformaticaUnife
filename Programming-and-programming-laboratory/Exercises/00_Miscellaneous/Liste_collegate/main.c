#include <stdio.h>
#include <stdlib.h>
#include "varieFunzioniListeCollegate.h"

int piena(Lista l);

int vuota(Lista l);

void stampa(Lista l);

void listaNonOrdinata(Lista *pl, int numero);

void azzera(Lista l);

int main(int argc, char *argv[])
{
    Lista ermenegilda;

    listaNonOrdinata(&ermenegilda, 6);
    stampa(ermenegilda);

    azzera(ermenegilda);

    stampa(ermenegilda);
}

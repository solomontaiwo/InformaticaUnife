#include <stdio.h>
#include "listeCollegatePrototipi.h"

int main(int argc, char *argv[])
{

    Lista bellaLista;

    listaNonOrdinata(&bellaLista, 2);

    stampa(bellaLista);

    insTesta(&bellaLista, 25);

    stampa(bellaLista);

    listaNonOrdinata(&bellaLista, 5);

    insTesta(&bellaLista, 777);

    stampa(bellaLista);
}
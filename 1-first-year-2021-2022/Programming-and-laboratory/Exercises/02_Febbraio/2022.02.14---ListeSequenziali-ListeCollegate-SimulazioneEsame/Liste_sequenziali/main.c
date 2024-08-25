#include "prot_liste_sequenziali.h"

int main(int argc, char *argv[])
{
    Lista tengen;

    inizializza(&tengen);

    insTesta(&tengen, 10);

    stampa(tengen);

    insOrd(&tengen, 2);

    stampa(tengen);

    insTesta(&tengen, 72);

    stampa(tengen);

    elim1(&tengen, 72);

    stampa(tengen);
}
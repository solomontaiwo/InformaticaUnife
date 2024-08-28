#include "liste_sequenziali_prototipi.h"

int main(int argc, char *argv[])
{
    Lista listaPiccina;

    inizializza(&listaPiccina);

    insOrd(&listaPiccina, 5);

    insOrd(&listaPiccina, 8);

    insOrd(&listaPiccina, 1);

    insOrd(&listaPiccina, 10);

    stampa(listaPiccina);

    insOrd(&listaPiccina, 1);

    stampa(listaPiccina);

    elim1(&listaPiccina, 5);

    stampa(listaPiccina);

    insOrd(&listaPiccina, 10);

    elimTutti(&listaPiccina, 1);

    stampa(listaPiccina);

    elimTutti(&listaPiccina, 10);

    stampa(listaPiccina);
}
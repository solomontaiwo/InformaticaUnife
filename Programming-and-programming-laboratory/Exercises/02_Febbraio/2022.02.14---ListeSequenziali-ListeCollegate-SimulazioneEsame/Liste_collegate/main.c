#include "dichiarazioniListeCollegate.h"

int main(int argc, char *argv[])
{

    Lista demon;

    listaNonOrdinata(&demon, 4);

    stampa(demon);

    insTesta(&demon, 666);

    stampa(demon);

    insertionSort(&demon);

    stampa(demon);

    elim1(&demon, 666);

    stampa(demon);
}
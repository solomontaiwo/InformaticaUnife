#include "tutteFunzioniListeCollegate.h"

int main(int argc, char *argv[])
{
    Lista finale;

    nuovaLista(&finale);

    listaNonOrdinata(&finale, 4);

    stampa(finale);

    elimTesta(&finale);

    stampa(finale);

    elim1(&finale, 41);

    stampa(finale);

    insTesta(&finale, 25);

    stampa(finale);
}
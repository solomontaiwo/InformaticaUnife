#include "programmaListeCollegate.h"

int main(int argc, char *argv[])
{
    Lista m;

    listaNonOrdinata(&m, 4);
    stampa(m);

    insTesta(&m, 50);
    stampa(m);
}
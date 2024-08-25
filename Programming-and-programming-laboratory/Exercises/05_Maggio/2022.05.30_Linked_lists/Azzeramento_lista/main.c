#include "generatoreListe.h"

int main(int argc, char *argv[])
{
    Lista prova;

    generatoreListe(&prova, 4);

    stampa(prova);

    azzera(prova);

    stampa(prova);

    return 0;
}
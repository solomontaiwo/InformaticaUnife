#include "reverse.h"

int main()
{
    Lista numeri;
    Lista inversi;

    generaLista(&numeri);

    stampa(numeri);

    reverse(numeri, &inversi);

    stampa(inversi);

    return 0;
}
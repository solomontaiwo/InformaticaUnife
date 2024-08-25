#include "frazioni.h"

int main()
{
    Frazione f1, f2;

    f1 = frazione(8, 2);
    stampaFrazionaria(f1);
    printf("\n");
    f2 = frazione(1, 5);
    stampaFrazionaria(somma(f1, f2));
    printf("\n");
}
#include <stdio.h>

typedef struct
{
    int numeratore;
    int denominatore;
} Frazione;

int main(int argc, char *argv[])
{
    Frazione f1, f2;

    f1 = frazione(-2, 3);
    f2 = frazione(7, 6);
}

Frazione frazione(int numeratore, int denominatore)
{
    Frazione f;
    f.numeratore = numeratore;
    f.denominatore = denominatore;
    return f;
}
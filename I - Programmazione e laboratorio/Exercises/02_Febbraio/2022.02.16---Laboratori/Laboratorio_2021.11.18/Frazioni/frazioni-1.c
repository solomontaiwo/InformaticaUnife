#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numeratore;
    int denominatore;
} Frazione;

Frazione frazione(int numeratore, int denominatore)
{
    Frazione f;
    f.numeratore = numeratore;
    f.denominatore = denominatore;
    return f;
}

Frazione leggiFrazione(void)
{
    int n, d;

    printf("Digita numeratore e denominatore: ");
    scanf("%d %d", &n, &d);

    return frazione(n, d);
}

void stampaFrazionaria(Frazione f)
{
    printf("%d/%d", f.numeratore, f.denominatore);
}

void stampaDecimale(Frazione f)
{
    printf("%.2f", (float)f.numeratore / f.denominatore);
}

int main(int argc, char *argv[])
{
    Frazione f1, f2;

    f1 = frazione(-2, 3);
    f2 = leggiFrazione();

    stampaFrazionaria(f1);
    puts("");
    stampaDecimale(f1);
    puts("");

    stampaFrazionaria(f2);
    puts("");
    stampaDecimale(f2);
    puts("");
}
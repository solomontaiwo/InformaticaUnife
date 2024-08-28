#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numeratore;
    int denominatore;
} Frazione;

int MCD(int a, int b)
{
    while (a != b)
        if (a > b)
            a = a - b;
        else
            b = b - a;
    return a;
}

int valAssoluto(int d)
{
    return d >= 0 ? d : -d;
}

void frazione(int n, int d, Frazione *pf)
{
    int m;
    if (d == 0)
    {
        printf("Errore: denominatore nullo.\n");
        exit(1);
    }
    if (n == 0)
    {
        pf->numeratore = 0;
        pf->denominatore = 1;
        return;
    }
    m = MCD(valAssoluto(n), valAssoluto(d));
    pf->numeratore = n / m;
    pf->denominatore = d / m;
}

void somma(Frazione f1, Frazione f2, Frazione *pf)
{
    frazione(f1.numeratore * f2.denominatore + f1.denominatore * f2.numeratore, f1.denominatore * f2.denominatore, pf);
}

void StampaFrazione(Frazione *pf)
{
    printf("%d/%d", pf->numeratore, pf->denominatore);
}

void leggiFrazione(Frazione *pf)
{
    int n, d;
    scanf("%d%d", &n, &d);
    frazione(n, d, pf);
}

int main(int argc, char *argv[])
{
    Frazione g1, g2, g3;
    leggiFrazione(&g1);
    leggiFrazione(&g2);
    somma(g1, g2, &g3);
    StampaFrazione(&g1);
    puts("");
    return 0;
}
#include <stdio.h>

int potenza(int base, int esponente)
{
    int contatore, prodotto = 1;
    for (contatore = 0; contatore < esponente; contatore++)
        prodotto = prodotto * base;

    return prodotto;
}

int main(void)
{
    printf("%d\n", potenza(2, 3));
}
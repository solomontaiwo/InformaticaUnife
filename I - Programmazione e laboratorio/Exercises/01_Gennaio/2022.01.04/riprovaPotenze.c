#include <stdio.h>

int potenza(int base, int esponente);
int base, esponente;

int main(void)
{
    printf("Dammi due numeri interi, base ed esponente, ti calcolero' la potenza: ");
    scanf("%d %d", &base, &esponente);
    printf("La potenza calcolata dai numeri che mi hai fornito e' %d.\n", potenza(base, esponente));
}

int potenza(int base, int esponente)
{
    int contatore, prodotto = 1;
    for (contatore = 0; contatore < esponente; contatore++)
        prodotto = prodotto * base;

    return prodotto;
}
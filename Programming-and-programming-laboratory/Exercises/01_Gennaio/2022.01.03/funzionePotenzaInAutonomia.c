// prova in autonomia di funzione potenza

#include <stdio.h>

int potenza(int base, int esponente);

int main(void)
{
    int base, esponente;
    printf("Inserisci un qualsiasi numero intero, te ne daro' il risultato della potenza: ");
    scanf("%d %d", &base, &esponente);
    printf("Il risultato della potenza di %d alla %d e' %d.\n", base, esponente, potenza(base, esponente));
    return 0;
}

int potenza(int base, int esponente)
{
    int contatore, prodotto = 1;
    for (contatore = 0; contatore < esponente; contatore++)
        prodotto = prodotto * base;
    return prodotto;
}
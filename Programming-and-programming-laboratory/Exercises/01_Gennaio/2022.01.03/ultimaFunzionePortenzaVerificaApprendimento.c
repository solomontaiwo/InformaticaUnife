#include <stdio.h>

int potenza(int base, int esponente);

int main()
{
    int base, esponente;
    printf("Dammi due valori interi, ti daro' il risultato in potenza: ");
    scanf("%d %d", &base, &esponente);
    printf("Eccoti la potenza di base %d ed esponente %d da te indicati: %d.\n", base, esponente, potenza(base, esponente));
}

int potenza(int base, int esponente)
{
    int contatore, prodotto = 1;
    for (contatore = 0; contatore < esponente; contatore++)
        prodotto = prodotto * base;

    return prodotto;
}
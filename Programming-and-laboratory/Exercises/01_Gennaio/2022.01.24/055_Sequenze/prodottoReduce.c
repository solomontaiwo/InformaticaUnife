// Scrivere un programma che stampi il prodotto dei cinque numeri interi inseriti dall’utente. //
#include <stdio.h>

int main()
{
    int numero, prodotto = 1;

    printf("Inserisci cinque numeri interi, ti mostrero' il loro prodotto.\n");

    for (int i = 0; i < 4; i++)
    {

        scanf("%d ", &numero);
        prodotto = (prodotto * numero);
    }

    printf("\nIl prodotto dei cinque numeri interi da te inseriti e' pari a %d.\n", prodotto);
}
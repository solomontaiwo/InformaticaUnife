/* Calcolare l’area e il perimetro di un rettangolo richiedendo all’utente la base e l’altezza 
Area = base * altezza, perimetro = doppio base sommato a doppio altezza*/

#include <stdio.h>

int main()
{
    int base, altezza;

    printf("Inserisci la base e l'altezza di un rettangolo, calcolero' l'area ed il perimetro: ");
    scanf("%d%d", &base, &altezza);

    printf("L'area del quadrato e' pari a %d.\n", base * altezza);
    printf("Il perimetro del rettangolo e' pari a %d.\n", (base * 2) + (altezza * 2));
}
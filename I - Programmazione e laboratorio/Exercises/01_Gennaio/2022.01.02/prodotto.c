// scrivere un programma che richieda all'utente 5 numeri, e poi stampi una riga contenenente l'uguaglianza fra l'espressione prodotto dei cinque numeri inseriti ed il risultato della moltiplicazione. Ad esempio: 2 x 4 x 5 x 3 x 2 x 4

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int input[5];
    int i;
    int p = 1; // accumulatore

    printf("Dammi cinque numeri interi, te ne daro' il prodotto (oltre a stampare i citati numeri): ");
    for (i = 0; i <= 4; i++)
        scanf("%d", &input[i]);

    for (i = 0; i <= 4; i++)
        p = p * input[i];

    for (i = 0; i < 4; i++)
        printf("%d x ", input[i]);

    printf("%d ", input[i]);

    printf("= %d\n", p);
}
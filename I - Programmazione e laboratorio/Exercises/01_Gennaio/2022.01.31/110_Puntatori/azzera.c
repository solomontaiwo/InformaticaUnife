// Scrivere una procedura di nome azzera che azzeri una variabile intera locale al chiamante. Testarla chiamandola in modo opportuno.
#include <stdio.h>

void azzera(int *pa)
{
    *pa = 0;
}

int main(void)
{
    int a;

    printf("Inserisci un valore, ti restituiro' la variabile azzerata (se tutto va bene): ");
    scanf("%d", &a);

    azzera(&a);

    printf("Valore finale: %d.\n", a);
}
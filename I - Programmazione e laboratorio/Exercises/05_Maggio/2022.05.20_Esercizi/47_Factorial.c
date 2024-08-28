#include <stdio.h>

int main(void)
{
    int numero, fattoriale = 1;

    printf("Inserisci un numero: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++)
        fattoriale = i * fattoriale;

    printf("Fattoriale di %d = %d\n", numero, fattoriale);
}
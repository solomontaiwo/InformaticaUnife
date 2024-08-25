#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero, val_temp, somma;

    printf("Inserisci un numero: ");
    scanf("%d", &numero);

    while (numero >= 1)
    {
        val_temp = numero % 10;
        somma = somma + val_temp;
        numero = numero / 10;
    }

    printf("Somma valori che compongono il numero: %d\n", somma);
}
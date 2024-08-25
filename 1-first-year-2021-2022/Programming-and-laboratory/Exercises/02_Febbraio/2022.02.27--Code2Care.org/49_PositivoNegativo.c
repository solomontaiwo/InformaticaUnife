#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero;

    printf("Inserisci un numero: ");
    scanf("%d", &numero);

    if (numero > 0)
        printf("Il numero %d e' positivo.\n", numero);
    else if (numero < 0)
        printf("Il numero %d e' negativo.\n", numero);
    else
        printf("Il numero %d non e' ne negativo ne' positivo.\n", numero);
}
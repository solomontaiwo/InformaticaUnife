#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero;
    int variabile_temporanea;
    int numeroInverso;

    printf("Inserisci un numero: ");
    scanf("%d", &numero);

    while (numero >= 1)
    {
        variabile_temporanea = numero % 10;                        // get unit place digit
        numeroInverso = numeroInverso * 10 + variabile_temporanea; // append above digit to reverse digit
        numero = numero / 10;                                      // rimuove ultima cifra
    }

    printf("Numero invertito: %d\n", numeroInverso);
}
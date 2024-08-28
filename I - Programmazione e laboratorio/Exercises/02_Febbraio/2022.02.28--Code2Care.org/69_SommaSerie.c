#include <stdio.h>

int main(int argc, char *argv[])
{
    int somma, numero;
    
    printf("Inserisci un numero: ");
    scanf("%d", &numero);

    for (int i = 0; i <= numero; i++)
        somma += i;
    printf("%d\n", somma);
}
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero, var_temp;

    printf("Inserisci un numero: ");
    scanf("%d", &numero);

    while (numero >= 1)
    {
        var_temp = numero % 10;
        printf("%d ", var_temp);
        numero = numero / 10;
    }
    puts("");
}

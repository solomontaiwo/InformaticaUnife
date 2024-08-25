#include <stdio.h>
#include <stdlib.h>

int main()
{
    double num1;
    double num2;
    char op;

    printf("Inserisci un numero: ");
    scanf("%lf", &num1);
    printf("Inserisci l'operatore: ");
    scanf(" %c", &op);
    printf("Inserisci un altro numero: ");
    scanf("%lf", &num2);

    if (op == '+')
    {
        printf("%f\n", num1 + num2);
    }
    else if (op == '-')
    {
        printf("%f\n", num1 - num2);
    }
    else if (op == '/')
    {
        printf("%f\n", num1 / num2);
    }
    else if (op == '*')
    {
        printf("%f\n", num1 * num2);
    }
    else
        printf("Operatore non valido.\n");
}
#include <stdio.h>

int main(int argc, char *argv[])
{

    int num1, num2;
    int somma;

    printf("inserisci due numeri interi: ");
    scanf("%d %d", &num1, &num2);

    somma = num1 + num2;

    printf("La somma dei numeri che hai inserito e' pari a %d.\n", somma);
}
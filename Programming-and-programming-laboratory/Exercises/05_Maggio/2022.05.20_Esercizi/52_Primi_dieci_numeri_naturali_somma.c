#include <stdio.h>

int main(int argc, char *argv[])
{

    int somma = 0;

    for (int i = 1; i <= 10; i++)
    {
        somma = somma + i;
        printf("%d ", i);
    }

    printf("\nLa somma dei primi dieci numeri naturali e' %d\n", somma);
}
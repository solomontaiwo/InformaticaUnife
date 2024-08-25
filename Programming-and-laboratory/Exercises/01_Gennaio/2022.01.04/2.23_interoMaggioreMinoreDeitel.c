// Questo programma determina e stampa il valore maggiore e minore di un gruppo di tre interi

#include <stdio.h>

int main(void)

{
    int a, b, c;

    printf("Immetti tre numeri interi, ti mostrero' il maggiore ed il minore: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a > b && a > c)
        printf("Maggiore: %d.\n", a);
    else
    {
        if (b > a && b > c)
            printf("Maggiore: %d.\n", b);
        else
            printf("Maggiore: %d.\n", c);
    }

    if (a < b && a < c)
        printf("Minore: %d.\n", a);
    else
    {
        if (b < a && b < c)
            printf("Minore: %d.\n", b);
        else
            printf("Minore: %d.\n", c);
    }
}
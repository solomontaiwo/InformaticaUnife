// Scrivere un programma che richiede all'utente 5 numeri interi e stampa il più grande
#include <stdio.h>
main()
{
    int a, b; // b = accumulatore
    int i;
    scanf("%d", &b);
    for (i = 1; i < 5; i++)
    {
        scanf("%d", &a);
        if (b < a)
            b = a;
    }
    printf("%d\n", b);
}
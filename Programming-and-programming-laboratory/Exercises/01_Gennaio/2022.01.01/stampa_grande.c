#include <stdio.h>

int a, i;
int acc = 0;

int main()
{

    printf("Inserisci cinque numeri interi, ti riportero' solo quello più grande: \n");

    {
        for (i = 0; i < 5; i++)
            scanf("%d", &a);
        if (a > acc)
        {
            acc = a;
        }
    }
    printf("%d\n", acc);
}
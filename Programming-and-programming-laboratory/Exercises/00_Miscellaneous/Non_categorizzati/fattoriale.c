#include <stdio.h>
int fatt(int n)
{
    int i = 0;
    int acc = 1;
    for (i = 1; i <= n; i++)
        acc = acc * i;
    return acc;
}

int main(int n)
{
    int i;
    int acc;
    printf("Inserisci un numero intero, ti dirò il suo fattoriale.\n");
    scanf("%d", &i);
    printf("Il fattoriale di %d è %d.\n", i, fatt(i));
}
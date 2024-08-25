#include <stdio.h>
// valore assoluto di numero inserito da utente
int m;
int va;

int valoreAssoluto(int n)
{
    if (n >= 0)
        va = n;
    else
        va = -n;
    return va;
}

int main(void)
{
    printf("Dammi un numero, ti dirò il suo valore assoluto.\n");
    scanf("%d", &m);
    printf("Il valore assoluto di %d è %d.\n", m, valoreAssoluto(m));
}
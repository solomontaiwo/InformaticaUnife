#include <stdio.h>

int main(int argc, char *argv[])
{

    int n, totale = 0;

    printf("Inserisci un numero: ");
    scanf("%d", &n);

    printf("1");

    for (int i = 1; i <= n; i++)
    {
        printf(" + 1/%d", i);
        totale = totale + i;
    }

    printf(" = 1/%d", totale);
    puts("");
}
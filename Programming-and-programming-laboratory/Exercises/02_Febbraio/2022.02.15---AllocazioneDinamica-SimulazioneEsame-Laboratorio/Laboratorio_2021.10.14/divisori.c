#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, d;

    printf("Inserisci un valore: ");
    scanf("%d", &n);

    for (d = 2; d <= n; d++)
    {
        if (n % d == 0)
        {
            printf("%d\n", d);
        }
    }
}
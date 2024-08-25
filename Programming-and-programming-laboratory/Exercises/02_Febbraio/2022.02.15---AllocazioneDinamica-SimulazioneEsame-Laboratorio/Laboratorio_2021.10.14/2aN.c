#include <stdio.h>

int main(int argc, char *argv[])
{
    int n;
    int i;

    printf("Inserisci un valore: ");
    scanf("%d", &n);

    for (int i = 2; i <= n; i++)
        printf("%d ", i);
}
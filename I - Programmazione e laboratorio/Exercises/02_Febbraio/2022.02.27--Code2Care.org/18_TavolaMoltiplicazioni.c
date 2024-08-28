#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero, i;

    printf("Inserisci il numero di cui vuoi la tavola di moltiplicazione: ");
    scanf("%d", &numero);

    for (i = 0; i <= 10; i++)
        printf("%d x %d = %d\n", numero, i, numero * i);
    puts("");

    printf("Inserisci un altro numero du cui vuol la tavola di moltiplicazione: ");
    scanf("%d", &numero);

    i = 0;

    while (i <= 10)
    {
        printf("%d x %d = %d\n", numero, i, numero * i);
        i++;
    }
}
#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, i;
    int array[n];

    printf("Inserisci il numero di elementi da inserire nell'array:\n");
    scanf("%d", &n);

    printf("Inserisci i %d elementi all'interno dell'array:\n");
    for (i = 0; i < n; i++)
    {
        printf("Elemento - %d : ", i);
        scanf("%d", array + i);
    }

    printf("\n\nElementi inseriti:\n");
    for (i = 0; i < n; i++)
        printf("Elemento - %d : %d\n", i, *(array + i));

    return 0;
}
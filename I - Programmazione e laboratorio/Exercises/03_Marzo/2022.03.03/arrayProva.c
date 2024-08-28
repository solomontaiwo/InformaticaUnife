#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *array;
    int dimensioni;

    printf("Inserisci un valore: ");
    scanf("%d", &dimensioni);

    array = malloc(sizeof(int) * dimensioni);

    for (int i = 0; i < dimensioni; i++)
        scanf("%d", &array[i]);

    for (int i = 0; i < dimensioni; i++)
        printf("%d ", array[i]);
    puts("");
}
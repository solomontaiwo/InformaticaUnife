#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int *array;
    int dimensioni;

    printf("Quanti elementi dovrebbero essere nell'array?\n");

    scanf("%d", &dimensioni);

    array = (int *)malloc(sizeof(int) * dimensioni);

    for (int i = 0; i < dimensioni; i++)
        array[i] = i;

    printf("I valori all'interno dell'array sono: ");

    for (int i = 0; i < dimensioni; i++)
        printf("%d ", array[i]);
    puts("");
}
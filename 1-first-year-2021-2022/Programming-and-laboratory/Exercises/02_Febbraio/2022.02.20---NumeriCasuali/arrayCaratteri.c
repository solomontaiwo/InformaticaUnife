#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int *array;
    int numeroElementi;

    printf("Inserisci il numero di elementi nell'array: ");
    scanf("%d", &numeroElementi);

    array = (int*)malloc(sizeof(int) * numeroElementi);

    srand(time(NULL));

    for (int i = 0; i < numeroElementi; i++)
        array[i] = 25 + rand() % (50 - 25 + 1);

    for (int j = 0; j < numeroElementi; j++)
        printf("%d ", array[j]);
    puts("");
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array;
    int dimensioni;

    printf("Dimensioni: ");
    scanf("%d", &dimensioni);

    array = (int *)malloc(dimensioni * sizeof(int));

    for (int i = 0; i < dimensioni; i++)
        scanf("%d", &array[i]);

    puts("");

    for (int i = 0; i < dimensioni; i++)
        printf("%d ", array[i]);
    puts("");

    free(array);
}
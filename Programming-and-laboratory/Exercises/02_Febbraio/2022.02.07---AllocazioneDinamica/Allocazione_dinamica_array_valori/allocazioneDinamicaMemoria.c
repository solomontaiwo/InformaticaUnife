#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valore;
    int *array;

    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &valore);

    array = (int *)malloc(valore * sizeof(int));

    printf("Inserisci gli elementi all'interno dell'array: ");
    for (int i = 0; i < valore; i++)
        scanf("%d", &array[i]);

    printf("Valori all'intero dell'array: ");
    for (int i = 0; i < valore; i++)
        printf("%d ", array[i]);
    puts("");
}
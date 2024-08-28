// stampa tutti i valori dell'array utilizzando un puntatore

#include <stdio.h>
#include <stdlib.h>

int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int *ptr = NULL;
int i;
ptr = a;

/* int main()
{
    for (i = 0; i < 10; i++)
        printf("%d ", array[i]);
    printf("\n");
} */

int main()
{

    for (i = 0; i < 10; i++)
        printf("%d ", *(ptr + i));
}

#include <stdio.h>
#define SIZE 10

int main(void)
{
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    printf("Dati nell'ordine originario: ");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }

    for (int passaggio = 1; passaggio < SIZE - 1; passaggio++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (a[i] > a[i + 1])
            {
                int fermo = a[i];
                a[i] = a[i + 1];
                a[i + 1] = fermo;
            }
        }
    }
    printf("\nDati in ordine crescente: ");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

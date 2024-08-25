#include <stdio.h>
#define SIZE 5

int main(int argc, char *argv[])
{
    int numeri[SIZE], i;

    printf("Inserisci %d valori: ", SIZE);

    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &numeri[i]);
    }

    puts("Array iniziale: ");

    for (i = 0; i < SIZE; i++)
        printf("%d ", numeri[i]);
    puts("");

    for (i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (numeri[j] > numeri[j + 1])
            {
                int temp = numeri[j];
                numeri[j] = numeri[j + 1];
                numeri[j + 1] = temp;
            }
        }
    }

    puts("Array finale: ");

    for (i = 0; i < SIZE; i++)
        printf("%d ", numeri[i]);
    puts("");
}
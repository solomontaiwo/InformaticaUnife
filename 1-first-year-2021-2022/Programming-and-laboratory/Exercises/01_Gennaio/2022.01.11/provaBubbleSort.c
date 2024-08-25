#include <stdio.h>
#define SIZE 10

int main(void)
{
    int valori[SIZE];

    printf("Dammi dieci valori, te li mettero' in ordine:\n");

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &valori[i]);
    }

    printf("\nEcco i valori che hai inserito: \n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", valori[i]);
    }
    puts("");

    printf("\nOra ti stampero' i valori che hai inserito in ordine crescente: \n");

    for (int passaggio = 0; passaggio < SIZE - 1; passaggio++)
    {
        for (int i = 0; i < SIZE - 1; i++)
        {
            if (valori[i] > valori[i + 1])
            {
                int fermo = valori[i];
                valori[i] = valori[i + 1];
                valori[i + 1] = fermo;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", valori[i]);
    }
    puts("");
}
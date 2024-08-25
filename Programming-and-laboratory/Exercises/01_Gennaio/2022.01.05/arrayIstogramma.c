#include <stdio.h>
#define SIZE 5

int main(void)
{
    int n[SIZE] = {19, 3, 15, 7, 11};

    printf("%s%20s%20s\n", "Elemento", "Valore", "Istogramma");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d%25d            ", i, n[i]);

        for (int j = 1; j <= n[i]; j++)
        {
            printf("%c", '*');
        }
        printf("\n");
    }
}
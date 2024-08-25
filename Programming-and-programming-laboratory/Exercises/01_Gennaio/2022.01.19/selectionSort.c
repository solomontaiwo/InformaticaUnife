#include <stdio.h>
#define SIZE 7

void selectionSort(int valori[], int lunghezza);

int main()

{
    int numeri[SIZE] = {9, 78, 2, 21, 99, 55, 1};

    for (int i = 0; i < SIZE; i++)
        printf("%d ", numeri[i]);
    puts("");

    selectionSort(numeri, SIZE);

    for (int i = 0; i < SIZE; i++)
        printf("%d ", numeri[i]);
    puts("");
}

void selectionSort(int valori[], int lunghezza)
{

    for (int i = 0; i < SIZE; i++)
    {
        size_t piccolo = i;

        for (int j = i + 1; j < SIZE; j++)
        {
            if (valori[piccolo] > valori[j])
            {
                int temp = valori[piccolo];
                valori[piccolo] = valori[j];
                valori[j] = temp;
            }
        }
    }
}
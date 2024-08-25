#include <stdio.h>
#define SIZE 7

void bubbleSort(int valori[], int lunghezza);

int main()

{
    int numeri[SIZE] = {9, 78, 2, 21, 99, 55, 1};

    for (int i = 0; i < SIZE; i++)
        printf("%d ", numeri[i]);
    puts("");

    bubbleSort(numeri, SIZE);

    for (int i = 0; i < SIZE; i++)
        printf("%d ", numeri[i]);
    puts("");
}

void bubbleSort(int valori[], int lunghezza)
{

    for (int passaggio = 0; passaggio < SIZE; passaggio++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (valori[i] > valori[i + 1])
            {
                int temp = valori[i];
                valori[i] = valori[i + 1];
                valori[i + 1] = temp;
            }
        }
    }
}
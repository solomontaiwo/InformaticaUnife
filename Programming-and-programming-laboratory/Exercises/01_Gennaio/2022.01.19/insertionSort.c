#include <stdio.h>
#define SIZE 7

void insertionSort(int valori[], int lunghezza);

int main()

{
    int numeri[SIZE] = {9, 78, 2, 21, 99, 55, 1};

    for (int i = 0; i < SIZE; i++)
        printf("%d ", numeri[i]);
    puts("");

    insertionSort(numeri, SIZE);

    for (int i = 0; i < SIZE; i++)
        printf("%d ", numeri[i]);
    puts("");
}

void insertionSort(int valori[], int lunghezza)
{

    for (int i = 0; i < SIZE; i++)
    {
        int posizione = i;
        int elementoInserire = valori[i];

        while (posizione > 0 && valori[posizione - 1] > elementoInserire)
        {
            valori[posizione] = valori[posizione - 1];
            posizione--;
        }
        valori[posizione] = elementoInserire;
    }
}
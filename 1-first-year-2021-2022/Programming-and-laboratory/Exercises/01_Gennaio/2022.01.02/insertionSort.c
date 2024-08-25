#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// creo la funzione insertionSort
void insertionSort(int a[], int lenght);

int main()
{
    int a[] = {8, 4, 9, 5, 7, 6, 3, 2};
    int i;

    insertionSort(a, 8);
    for (i = 0; i < 8; i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}

// definisco la funzione creata inizialmente alla riga 6
void insertionSort(int a[], int lenght)
{
    for (int i = 1; i < lenght; i++)
    {
        int key = a[i];
        int j = i - 1; // verifico da questo elemento in poi (numero prima di quello che sto esaminando)

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
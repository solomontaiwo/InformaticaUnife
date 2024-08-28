#include <stdio.h>
#define SIZE 5

void selectionSort(int array[], int lunghezza);
void swap(int array[], int primoElemento, int secondoElemennto);

int main()
{
    int arraySoggetto[SIZE] = {88, 1, 65, 9, 4};

    printf("Array disordinato (iniziale): ");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arraySoggetto[i]);
    }

    puts("");

    selectionSort(arraySoggetto, SIZE);

    printf("Array ordinato (finale): ");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arraySoggetto[i]);
    }

    puts("");
}

void selectionSort(int array[], int lunghezza)
{
    for (int i = 0; i < SIZE; i++)
    {
        int piuPiccolo = i;
        for (int j = i + 1; j < SIZE; j++)
        {
            if (array[j] < array[piuPiccolo])
            {
                piuPiccolo = j;
            }
        }
        swap(array, i, piuPiccolo);
    }
}

void swap(int array[], int primoElemento, int secondoElemennto)
{
    int temp = array[primoElemento];
    array[primoElemento] = array[secondoElemennto];
    array[secondoElemennto] = temp;
}
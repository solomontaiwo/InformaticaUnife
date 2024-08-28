#include <stdio.h>
#define SIZE 10

void selectionSort(int array[], size_t lunghezza);
void swap(int array[], size_t primo, size_t secondo);

int main(void)
{

    int voto[SIZE] = {5, 6, 3, 1, 7, 10, 2, 8, 4, 9};

    puts("Array iniziale, non ordinato: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", voto[i]);
    }
    puts("");

    selectionSort(voto, SIZE);

    puts("Array finale, ordinato: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", voto[i]);
    }
    puts("");
}

void selectionSort(int array[], size_t lunghezza)
{
    for (size_t i = 0; i < lunghezza - 1; i++)
    {
        size_t piccolissimo = i;
        for (size_t j = i + 1; j < lunghezza; j++)
        {
            if (array[j] < array[piccolissimo])
            {
                piccolissimo = j;
            }
        }
        swap(array, i, piccolissimo);
    }
}

void swap(int array[], size_t primo, size_t secondo)
{
    int temp = array[primo];
    array[primo] = array[secondo];
    array[secondo] = temp;
}

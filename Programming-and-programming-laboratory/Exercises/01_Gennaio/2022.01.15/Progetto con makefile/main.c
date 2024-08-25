#include <stdio.h>
#define SIZE 10

void bubbleSort(int array[], size_t lenght);

int main(void)
{
    int array[SIZE] = {2, 3, 10, 4, 6, 1, 7, 8, 5, 9};

    printf("Array iniziale, non ordinato: ");
    for (int i = 0; i < SIZE - 1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("%d.", array[SIZE - 1]);
    puts("");

    bubbleSort(array, SIZE);

    printf("Array finale, ordinato: ");
    for (int i = 0; i < SIZE - 1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("%d.", array[SIZE - 1]);
    puts("");
}
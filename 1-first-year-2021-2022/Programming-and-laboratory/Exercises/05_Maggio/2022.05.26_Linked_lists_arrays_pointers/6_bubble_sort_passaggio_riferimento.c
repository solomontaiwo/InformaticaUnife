#include <stdio.h>
#define SIZE 10

void bubbleSort(int *ptr, int size);
void swap(int *primoElemento, int *secondoElemento);

int main(int argc, char *argv[])
{
    int numeri[SIZE];

    puts("Inserisci dieci numeri: ");

    for (int i = 0; i < SIZE; i++)
        scanf("%d", &numeri[i]);

    bubbleSort(numeri, SIZE);

    for (int i = 0; i < SIZE; i++)
        printf("%d ", numeri[i]);
    puts("");

    return 0;
}

void bubbleSort(int *ptr, int size)
{
    void swap(int *primoElemento, int *secondoElemento);

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                swap(&ptr[j], &ptr[j + 1]);
            }
        }
    }
}

void swap(int *primoElemento, int *secondoElemento)
{
    int temp = *primoElemento;
    *primoElemento = *secondoElemento;
    *secondoElemento = temp;
}

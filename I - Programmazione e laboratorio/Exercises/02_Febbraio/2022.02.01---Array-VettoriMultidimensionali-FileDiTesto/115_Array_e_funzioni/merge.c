/* Scrivere una procedura che riceva due array ordinati in senso crescente, e ne crei un terzo, sempre ordinato in senso crescente, contenente gli elementi dei primi due. 
Ad esempio, se il primo array contiene 1, 3, 4, 4, 5 e i secondo 0, 1, 4, 6, 7, l’array risultante deve contenere 0, 1, 1, 3, 4, 4, 4, 5, 6, 7. 
*/
#include <stdio.h>
#define SIZE 5

int swap(int array[], int primoValore, int secondoValore);
void merge(int primoArray[], int secondoArray[], int terzoArray[], int lunghezza);
int selectionSort(int array[], int lunghezza);

int main(void)
{

    int array1[SIZE], array2[SIZE], arrayComplessivo[SIZE + SIZE];

    puts("Inserisci dieci valori complessivi, andranno in due array che saranno poi ordinati in senso crescente.");

    printf("Primi cinque valori: ");
    for (int i = 0; i < SIZE; i++)
        scanf("%d", &array1[i]);

    printf("Ulteriori cinque valori: ");
    for (int i = 0; i < SIZE; i++)
        scanf("%d", &array2[i]);

    merge(array1, array2, arrayComplessivo, SIZE);

    selectionSort(arrayComplessivo, SIZE + SIZE);

    printf("Array complessivo ordinato: ");
    for (int i = 0; i < SIZE + SIZE; i++)
        printf("%d ", arrayComplessivo[i]);
    puts("");
}

int selectionSort(int array[], int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
    {
        int piccolo = i;
        for (int j = i + 1; j < lunghezza; j++)
        {
            if (array[piccolo] > array[j])
            {
                piccolo = j;
            }
        }
        swap(array, i, piccolo);
    }
}

int swap(int array[], int primoValore, int secondoValore)
{
    int temp = array[primoValore];
    array[primoValore] = array[secondoValore];
    array[secondoValore] = temp;
}

void merge(int primoArray[], int secondoArray[], int terzoArray[], int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
    {
        terzoArray[i] = primoArray[i];
    }

    for (int i = 0; i < lunghezza; i++)
    {
        terzoArray[i + lunghezza] = secondoArray[i];
    }
}
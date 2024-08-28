/* Scrivere un programma che
1 richieda in ingresso un massimo di 10 numeri interi non nulli (fermandosi quando l’utente digita 0) memorizzandoli in un array;
2 ordini l’array secondo l’ordine crescente dei quadrati dei suoi elementi, usando l’algoritmo insertion sort;
3 stampi l’array.
*/
#include <stdio.h>
#define SIZE 10

void selectionSort(int array[], int lunghezza);
void swap(int array[], int primoValore, int secondoValore);

int main()
{
    int numeri[SIZE], i = 0, dimlog = 0;

    while (dimlog < SIZE)
    {
        scanf("%d", &numeri[dimlog]);
        if (numeri[dimlog] == 0)
        {
            break;
        }

        else
        {
            dimlog++;
        }
    }

    puts("I valori da te inseriti sono i seguenti:");

    for (i = 0; i < dimlog; i++)
    {
        printf("%d ", numeri[i]);
    }

    puts("");

    // faccio il quadrato degli elementi dell'array creato dall'utente
    for (i = 0; i < dimlog; i++)
    {
        numeri[i] = numeri[i] * numeri[i];
    }

    printf("Ora te li mettero' in ordine (al quadrato): ");

    selectionSort(numeri, dimlog);

    for (i = 0; i < dimlog; i++)
    {
        printf("%d ", numeri[i]);
    }
    puts("");
}

void selectionSort(int array[], int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
    {
        int piccolo = i;

        for (int j = i + 1; j < lunghezza; j++)
        {
            if (array[j] < array[piccolo])
            {
                piccolo = j;
            }
        }
        swap(array, i, piccolo);
    }
}

void swap(int array[], int primoValore, int secondoValore)
{
    int temp = array[primoValore];
    array[primoValore] = array[secondoValore];
    array[secondoValore] = temp;
}
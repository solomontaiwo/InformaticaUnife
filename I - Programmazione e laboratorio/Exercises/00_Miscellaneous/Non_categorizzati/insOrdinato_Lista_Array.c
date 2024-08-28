#include <stdio.h>
#include <stdlib.h>
#define DIM 20

typedef struct
{
    int n_elementi;
    int dati[DIM];
} Lista;

// Inserimento ordinato in lista sequenziale
void insOrd(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("La lista per sfortuna è piena, non puoi inserire altri valori.\n");
        exit(-1);
    }
    else
    {
        int i;
        i = pl->n_elementi;

        while (i > 0 && pl->dati[i - 1] > numero)
        {
            pl->dati[i] = pl->dati[i - 1];
            i--;
        }
        pl->dati[i] = numero;
        pl->n_elementi++;
    }
}

// Inserimento ordinato in array

void insertionSort(int array[], int lunghezza)
{
    for (int i = 1; i < lunghezza; i++)
    {
        int posizioneElemento = i;
        int elemento = array[i];

        while (posizioneElemento > 0 && array[posizioneElemento - 1] > elemento)
        {
            array[posizioneElemento] = array[posizioneElemento - 1];
            posizioneElemento--;
        }
        array[posizioneElemento] = elemento;
    }
}

// Selezione ordinata in array

void selectionSort(int array[], int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
    {
        int piccolo = i;
        for (int j = i + 1; j < lunghezza; j++)
        {
            if (array[j] < array[i])
            {
                piccolo = j;
            }
        }
        swap(array, i, piccolo);
    }
}

// Swap

void swap(int array[], int primoValore, int secondoValore)
{
    int temp = array[primoValore];
    array[primoValore] = array[secondoValore];
    array[secondoValore] = temp;
}

// Inserimento ordinato in lista, secondo tentativo

void insOrd(Lista *pl, int numero)
{
    if (piena(*pl))
    {
        printf("La lista e' piena.\n");
        exit(-1);
    }
    else
    {
        int i = pl->n_elementi;
        while (i > 0 && pl->dati[i - 1] > numero)
        {
            pl->dati[i] = pl->dati[i - 1];
            i--;
        }
        pl->dati[i] = numero;
        pl->n_elementi++;
    }
}
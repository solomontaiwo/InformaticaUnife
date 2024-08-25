#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "insertionSort_mergeSort_hybridSort.h"

// Unione di due subarray arr[]. p = indice inizio array, q = centro array, r = fine array.
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Array temporanei
    int L[n1], R[n2];

    // Copia dei dati negli array temporanei L[] ed R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; // Indice iniziale del primo subbarray
    j = 0; // Indice iniziale del primo subbarray
    k = l; // k = Indice iniziale dell'array unito

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copia degli elementi restanti di L[], se ci sono
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copia degli elementi restanti di R[], se ci sono
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l è il l'indice di inizio dell'array *arr, r è la dimensione
void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        // Centro dell'array
        int m = (l + r) / 2;

        // Ordina la prima e la seconda metà
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void insertionSort(int *arr, int length)
{
    int i, key, j;
    for (i = 0; i < length; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// dichiarazione della funzione che calcola il tempo impiegato per ordinare con l'insertion sort un array di lunghezza minima "min_length" e massima "max_length"
void experiment(int min_length, int max_length)
{
    int max_instances = 7; // numero massimo di array i cui elementi verranno generati casualmente e poi riordinati
    int step = 50;         // quantità di incremento da una lunghezza all'altra
    int tries = 1;         // contatore numero di tentatitvi eseguiti, stampato su terminale
    int length;
    float timeInsertionSort = 0, timeMergeSort = 0;
    FILE *fp;

    fp = fopen("Output/insertionSort_mergeSort.txt", "w");

    /* ciclo che, grazie alla funzione "singleExperiment", calcola il tempo necessario per creare e mettere in ordine gli elementi di un array casuale;
    Dopo l'ottenimento del tempo, vengono stampati il numero del tentativo, la dimensione dell'array considerato ed il numero del tentativo effettuato.
    Il ciclo va avanti in incrementi di "step" fino a raggiungere la lunghezza massima "max_length" */
    for (length = min_length; length <= max_length; length += step)
    {
        timeInsertionSort = singleExperimentInsertionSort(length, max_instances);
        printf("Tentativo #%d\nDimensione array: %d\nTempo: %.2f\n\n", tries, length, timeInsertionSort);
        fprintf(fp, "Dimensione: %d %.2f\n", length, timeInsertionSort);
        tries++;
    }
    fclose(fp);
}

/* dichiarazione della funzione che inizializza un array "array" di lunghezza "length"
e restituisce il tempo medio necessario per ordinare con insertion sort gli elementi al suo interno */
float singleExperimentInsertionSort(int length, int max_instances)
{
    float time_tot_insertionSort = 0, time_tot_mergeSort = 0, time_start, time_end, time_elapsed;
    int *array1 = malloc(length);
    int *array2 = malloc(length);
    int instance;

    // ciclo che genera un array casuale e calcola il tempo necessario per ordinarlo
    for (instance = 0; instance < max_instances; instance++)
    {
        generateRandomArray(array1, length); // generazione di un array casuale di lunghezza "length"
        array2 = array1;
        time_start = clock(); // misurazione del tempo prima dell'insertion sort
        insertionSort(array1, length);
        time_end = clock();
        time_elapsed = time_end - time_start;
        time_tot_insertionSort += time_elapsed; // somma totale del tempo dell'insertion sort
    }

    return time_tot_insertionSort / max_instances; // restituzione alla funzione chiamante del tempo medio dell'insertion sort per "max_instances"
}

// dichiarazione della funzione che genera un array di numeri casuali con seed 20
void generateRandomArray(int *array, int length)
{
    srand(20);
    for (int i = 0; i <= length; i++)
        array[i] = rand();
}

// Funzione per stampare un array
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

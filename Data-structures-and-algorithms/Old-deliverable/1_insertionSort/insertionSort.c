#include <stdio.h>
#include <stdlib.h> // per srand()
#include <time.h>   // per clock()
#include "insertionSort.h"

// Funzione che calcola il tempo impiegato per ordinare con l'insertion sort un array di lunghezza minima "min_length" e massima "max_length"
void experiment(int min_length, int max_length)
{
    int max_instances = 50; // numero massimo di array i cui elementi verranno generati casualmente e poi riordinati
    int step = 1000;        // quantità di incremento da una lunghezza all'altra
    int tries = 1;          // contatore numero di tentatitvi eseguiti, stampato su terminale
    int length;
    float time = 0;
    FILE *fp;

    fp = fopen("Output/insertionSort.txt", "w"); // creazione file di output dati

    /* ciclo che, grazie alla funzione "singleExperiment", calcola il tempo necessario per creare e mettere in ordine gli elementi di un array casuale;
    Dopo l'ottenimento del tempo, vengono stampati il numero del tentativo, la dimensione dell'array considerato ed il numero del tentativo effettuato.
    Il ciclo va avanti in incrementi di "step" fino a raggiungere la lunghezza massima "max_length" */
    for (length = min_length; length <= max_length; length += step)
    {
        time = singleExperiment(length, max_instances);
        printf("Tentativo #%d\nDimensione array: %d\nTempo: %.2f\n\n", tries, length, time);
        fprintf(fp, "Dimensione: %d %.2f\n", length, time);
        tries++;
    }
    fclose(fp);
}

/* Funzione che inizializza un array "array" di lunghezza "length" e
restituisce il tempo medio necessario per ordinare con insertion sort gli elementi al suo interno */
float singleExperiment(int length, int max_instances)
{
    float t_tot = 0, time_start, time_end, time_elapsed;
    int *array = malloc(length);
    int instance;

    // ciclo che genera un array casuale e calcola il tempo necessario per ordinarlo
    for (instance = 0; instance < max_instances; instance++)
    {
        generateRandomArray(array, length);   // generazione di un array casuale di lunghezza "length"
        time_start = clock();                 // misurazione del tempo prima dell'insertion sort
        insertionSort(array, length);         // chiamata della funzione insertion sort per ordinare l'array generato casualmente
        time_end = clock();                   // misurazione del tempo dopo l'insertion sort
        time_elapsed = time_end - time_start; // sottrazione del tempo iniziale da quello finale per ottenere il tempo utilizato dall'insertion sort
        t_tot += time_elapsed;                // somma totale del tempo dell'insertion sort
    }

    return t_tot / max_instances; // restituzione alla funzione chiamante del tempo medio dell'insertion sort per "max_instances"
}

// Funzione che genera un array di numeri casuali con seed 20
void generateRandomArray(int *array, int length)
{
    srand(20); // ATTENZIONE: HARD-CODED, DA IMPLEMENTARE FUORI DAL generateRandomArray
    for (int i = 0; i <= length; i++)
        array[i] = rand();
}

// Funzione di ordinamento degli array con insertion sort
void insertionSort(int *array, int length)
{
    int i, key, j;
    for (i = 0; i < length; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}
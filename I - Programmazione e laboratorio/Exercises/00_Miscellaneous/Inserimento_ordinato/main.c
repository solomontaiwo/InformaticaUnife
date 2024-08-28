#include <stdio.h>
#include "insertionSort.h"
#include "selectionSort.h"
#define SIZE 10

int elementi[SIZE];

int main()
{
    printf("Riordino di valori inseriti dall'utente.\nInserisci dieci valori, te li mettero' in ordine: ");

    for (int i = 0; i < SIZE; i++)
        scanf("%d", &elementi[i]);

    printf("Elementi non ordinati all'interno dell'array 'elementi': ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", elementi[i]);
    puts("");

    selectionSort(elementi, SIZE);

    printf("Elementi ordinati: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", elementi[i]);

    puts("");

    printf("Inserisci NUOVI valori: ");

    for (int i = 0; i < SIZE; i++)
        scanf("%d", &elementi[i]);

    insertionSort(elementi, SIZE);

    printf("NUOVI Elementi ordinati: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", elementi[i]);

    puts("");
}
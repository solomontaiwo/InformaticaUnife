/* Scrivere un programma che:
1. legga da tastiera un intero n e un array di n interi
2. tramite una funzione calcoli l’indice del massimo dell’array 
3. tramite una funzione visualizzi sullo schermo l’indice del massimo 
*/
#include <stdio.h>

int n, i;
int indice;
int interi[10];

int indiceMassimo(int array[], int lunghezza)
{
    for (i = 0; i < lunghezza; i++)
    {
        if (array[i] > array[indice])
            indice = i;
    }
    return indice;
}

int main(void)
{

    // fase 1
    printf("Inserisci un intero: ");
    scanf("%d", &n);

    printf("Inserisci un array di interi: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &interi[i]);
    }

    // fase 2

    indiceMassimo(interi, n);

    // fase3

    printf("L'indice a cui si trova il valore piu' grande e' [%d]\n", indice);
}
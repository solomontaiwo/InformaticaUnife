// Scrivere un programma che ricerchi in un array di interi un numero richiesto all’utente e, se lo trova, dica a quale indice. //
#include <stdio.h>
#define SIZE 5

int main()
{
    int array[] = {4, 3, 8, 5, 1};

    int elemento, trovato = 0, i = 0;

    printf("Inserisci un valore, ti diro' se si trova all'interno dell'array che ho in memoria: ");

    scanf("%d", &elemento);

    while (!trovato && i < SIZE)
    {
        if (array[i] == elemento)
        {
            break;
        }

        else
        {
            i++;
        }
    }

    printf("Il valore da te inserito, %d, si trova all'indice %d.\n", elemento, i);

    return 0;
}
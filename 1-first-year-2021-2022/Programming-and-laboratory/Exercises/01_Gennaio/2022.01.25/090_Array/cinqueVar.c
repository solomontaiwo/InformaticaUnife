// Scrivere un programma che richieda all’utente cinque numeri interi e li stampi in ordine inverso. Ad esempio, se l’utente digita i numeri 5, 3, 7, 8 e 2, il programma deve stampare 28735 (con variabile DIM per indicare la dimensione dell'array) //
#include <stdio.h>
#define SIZE 5

int main()
{
    int numeri[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &numeri[i]);
    }

    for (int i = SIZE - 1; i >= 0; i--)
    {
        printf("%d ", numeri[i]);
    }
    puts("");
}
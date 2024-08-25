// Scrivere un programma che inizializzi un array di 10 elementi ai 10 numeri che seguono un numero richiesto all’utente, e poi stampi l’array. //
#include <stdio.h>
#define SIZE 10

int main()
{
    int n;
    int array[SIZE];

    scanf("%d", &n);
    for (int i = 0; i < SIZE; i++)
    {
        n++;
        array[i] = n;
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    puts("");
}
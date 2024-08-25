// Scrivere un programma che inizializzi un array di 10 elementi ai quadrati dei primi 10 numeri naturali, e poi stampi l’array. //
#include <stdio.h>
#define SIZE 11

int main()
{
    int array[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = (i * i);
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    puts("");
}
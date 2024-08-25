// Riempire un array di interi con gli elementi positivi contenuti in un altro array di interi. //
#include <stdio.h>
#define SIZE 5

int primoArray[SIZE];
int secondoArray[SIZE];

int main()
{
    for (int i = 0; i < SIZE; i++)
    {
        primoArray[i] = i;
        printf("%d ", primoArray[i]);
    }

    puts("");

    for (int i = 0; i < SIZE; i++)
    {
        secondoArray[i] = primoArray[i];
        printf("%d ", secondoArray[i]);
    }

    puts("");
}
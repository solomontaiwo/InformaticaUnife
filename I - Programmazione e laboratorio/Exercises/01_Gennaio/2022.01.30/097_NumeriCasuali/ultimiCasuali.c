#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
    int i;
    double j;

    srand(time(NULL));

    for (i = 0; i < SIZE; i++)
        printf("Valori casuali interi: %d\n", 50 + rand() % (100 - 50 + 1));

    puts("");

    for (i = 0; i < SIZE; i++)
        printf("Valori casuali double: %.1f\n", 20.5 + (double)rand() / RAND_MAX * (60.5 - 20.5));
}
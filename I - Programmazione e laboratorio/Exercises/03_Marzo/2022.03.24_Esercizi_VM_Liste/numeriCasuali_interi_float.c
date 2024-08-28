#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main(int argc, char *argv[])
{
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
        printf("Valore intero casuale compreso tra 1 e 1000: %d\n", 1 + rand() % (1000 - 1 + 1));
    puts("");

    for (int i = 0; i < SIZE; i++)
        printf("Valore float compreso tra 1.5 e 999.9: %.2f\n", 1.5 + (double)rand() / RAND_MAX * (999.9 - 1.5));
    puts("");

    return 0;
}
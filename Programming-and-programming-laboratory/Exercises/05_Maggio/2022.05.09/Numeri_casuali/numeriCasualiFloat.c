#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));

    for (int i = 0; i < 50; i++)
        printf("Stampa numero %d: %.2f\n", i, 50.00 + (double)rand() / RAND_MAX * (100.00 - 50.00));
}
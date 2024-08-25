#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{

    srand(time(NULL));

    for (int i = 1; i <= 10; i++)
    {
        printf("Numero casuale n. %d: %.2f\n", i, 30.5 + (double)rand() / RAND_MAX * (55.5 - 30.5));
    }
}
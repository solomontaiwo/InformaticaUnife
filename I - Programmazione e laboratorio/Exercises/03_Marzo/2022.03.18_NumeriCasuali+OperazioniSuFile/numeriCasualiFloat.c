#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
        printf("%.2f\n", 50.0 + (double)rand() / RAND_MAX * (100.0 - 50.0));
}
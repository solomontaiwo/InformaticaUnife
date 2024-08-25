#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = 0; i < 10; i++)
        printf("%.2f ", 15.0 + (25.0 - 15.0) * (double)rand() / RAND_MAX);
}

int rand_int(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double rand_double(double min, double max)
{
    return min + (double)rand() / RAND_MAX * (max - min);
}
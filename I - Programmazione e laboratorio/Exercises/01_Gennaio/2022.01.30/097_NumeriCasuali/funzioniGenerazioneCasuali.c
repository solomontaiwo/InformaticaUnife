#include <stdlib.h>

int rand_Int(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int rand_double(double min, double max)
{
    return min + (double)rand() / RAND_MAX * (max - min);
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    printf("Hello World!\n");
    srand(time(NULL));
    printf("%.2f\n", 18.0 + (double)rand() / RAND_MAX * (30.0 - 18.0));
}
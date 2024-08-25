#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int n;
    n = rand();

    // printf("%d\n", RAND_MAX);
    // printf("%d\n", n);

    n = 1 + rand() % (6 - 1 + 1);
    printf("%d\n", n);
}
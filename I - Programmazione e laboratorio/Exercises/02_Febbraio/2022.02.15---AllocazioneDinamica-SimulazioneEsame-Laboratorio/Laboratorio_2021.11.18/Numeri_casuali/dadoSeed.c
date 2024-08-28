#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));

    /* for (int i = 0; i < 50; i++)
        printf("%d\n", 1 + rand() % (50 - 1 + 1));

    puts("");

    for (int i = 0; i < 100; i++)
        printf("%.2f\n", 50.0 + (double)rand() / RAND_MAX * (99.9 - 50.0));
        */

    for (int i = 0; i < 10; i++)
        printf("%d\n", 1 + rand() % (6 - 1 + 1));
}
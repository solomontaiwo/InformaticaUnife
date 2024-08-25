#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int n;
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
        printf("%d ", 50 + rand() % (100 - 50 + 1));
    puts("");

    for (int i = 0; i < 10; i++)
        printf("%.2f ", 10.00 + (double)rand() / RAND_MAX * (25.00 - 10.00));
    puts("");
}
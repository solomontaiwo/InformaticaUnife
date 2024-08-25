#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char argv[])
{
    int x = 2, y = 5;
    printf("%d", x && y);
    puts("");

    srand(time(NULL));

    printf("Valori tra 25 e 50:\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", 25 + rand() % (50 - 25 + 1));
    puts("");

    printf("Valori tra 50.00 e 70.00:\n");
    for (int j = 0; j < 10; j++)
        printf("%.2f ", 50 + (double)rand() / RAND_MAX * (70 - 50));
    puts("");
}
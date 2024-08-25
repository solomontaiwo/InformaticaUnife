#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));

    for (int i = 1; i <= 50; i++)
        printf("Stampa numero %d: %d\n", i, 50 + rand() % (100 - 50 + 1));
}
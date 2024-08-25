#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{

    srand(time(NULL));

    for (int i = 1; i <= 10; i++)
    {
        printf("Numero casuale n. %d: %d\n", i, 15 + rand() % (30 - 15 + 1));
    }
}
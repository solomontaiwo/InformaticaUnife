#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // Questo programma stampa 10 numeri casuali

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
        printf("%d ", 1 + rand() % (30 - 1 + 1));
        puts("");
}
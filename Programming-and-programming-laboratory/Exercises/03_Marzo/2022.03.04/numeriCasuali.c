#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    printf("Numero compreso tra 18 e 30: %d\n", 18 + rand() % (30 - 18 + 1));
}
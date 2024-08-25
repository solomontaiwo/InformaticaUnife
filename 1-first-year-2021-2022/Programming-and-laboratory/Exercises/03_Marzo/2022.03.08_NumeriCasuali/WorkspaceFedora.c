#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    printf("%d\n", 1 + rand() % (10 - 1 + 1));
}
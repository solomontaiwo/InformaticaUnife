#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = 0; i < 10; i++)
        printf("%d ", 1 + rand() % (6 - 1 + 1));
    puts("");
}
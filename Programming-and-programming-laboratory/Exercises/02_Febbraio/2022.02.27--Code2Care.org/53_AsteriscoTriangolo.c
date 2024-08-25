#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, j;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j <= i; j++)
            printf("* ");
        puts("");
    }
}
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = 0; i <= 20; i++)
    {
        if (i % 2 == 0)
            printf("%d ", i);
    }
    puts("");
}
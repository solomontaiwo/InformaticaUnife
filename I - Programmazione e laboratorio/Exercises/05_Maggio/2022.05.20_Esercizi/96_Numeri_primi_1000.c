#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, j = 2;
    for (i = 1; i <= 1000; i++)
    {
        j = 2;

        while (j <= i - 1)
        {
            if (i % j == 0)
            {
                break;
            }
            j++;
        }
        if (i == j)
            printf("%d\n", i);
    }
}
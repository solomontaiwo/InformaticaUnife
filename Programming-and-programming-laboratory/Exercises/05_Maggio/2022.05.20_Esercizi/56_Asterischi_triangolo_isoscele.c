#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i <= 11; i++)
    {
        for (j = 11; j >= i; j--)
        {
            printf(" ");
        }
        for (k = 1; k <= i; k++)
            printf(" * ");
        puts("");
    }
}
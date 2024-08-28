#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;

    for (a = 0; a <= 10; a++)
    {
        for (b = 10; b >= a; b--)
        {
            printf(" ");
        }
        for (c = 0; c < a; c++)
        {
            printf(" * ");
        }
        puts("");
    }
}
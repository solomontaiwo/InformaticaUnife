#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    printf("Di seguito i numeri pari da 0 a 20: ");

    for (i = 0; i <= 20; i++)
    {
        if (i % 2 == 0)
            printf("%d ", i);
    }
    puts("");
}
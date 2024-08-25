#include <stdio.h>

int main(void)
{
    int n[5];

    for (int i = 0; i < 5; i++)
    {
        n[i] = 0;
    }
    printf("%s%13s\n", "Elemento", "Valore");
    for (int i = 0; i < 5; i++)
    {
        printf("%5d%13d\n", i, n[i]);
    }
}
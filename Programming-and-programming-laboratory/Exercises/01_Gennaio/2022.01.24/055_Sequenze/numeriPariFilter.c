// Stampare la sequenza dei numeri pari compresi fra 1 e 20. //
#include <stdio.h>

int main()
{
    for (int i = 1; i <= 20; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d ", i);
        }
    }
}
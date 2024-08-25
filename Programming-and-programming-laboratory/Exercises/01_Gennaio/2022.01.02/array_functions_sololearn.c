#include <stdio.h>
#include <stdlib.h>

int addUp(int *a, int num_elements)
{
    int totale = 0;
    int i;

    for (i = 0; i < num_elements; i++)
    {
        totale = totale + a[i];
    };
    return totale;
}

int main()
{
    int orders[5] = {100, 220, 37, 16, 98};
    printf("Total orders is %d.\n", addUp(orders, 5));

    return 0;
}

// NOTA BENE: gli array SONO DEI PUNTATORI!
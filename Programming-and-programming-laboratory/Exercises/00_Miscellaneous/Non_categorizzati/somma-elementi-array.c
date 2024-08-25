#include <stdio.h>
#define DIM 5

int main(void)
{
    int a[DIM], i, s;

    for (i = 0; i < DIM; i++)
        scanf("%d", &a[i]);

    s = 0; // inizializzazione accumulatore

    for (i = 0; i < DIM; i++)
        s = s + a[i]; // aggiornamento accumulatore

    return 0;
}
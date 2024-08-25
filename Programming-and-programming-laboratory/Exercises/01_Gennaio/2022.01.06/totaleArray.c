#include <stdio.h>

int main(void)
{
    int totale = 0;
    int arrayBidimensionale[2][3] = {{1, 2, 3}, {4, 5, 6}};

    for (int riga = 0; riga < 2; riga++)
    {
        for (int colonna = 0; colonna < 3; colonna++)
        {
            totale = totale + arrayBidimensionale[riga][colonna];
        }
    }
    printf("%d ", totale);
}

#include <stdio.h>

int quadrato(int y); // prototipo della funzione square - dichiarazione della funzione square

int main(void)
{
    for (int x = 1; x <= 10; x++)
        printf("%d\n", quadrato(x));
}

// definizione funzione square
int quadrato(int y)
{
    return y * y;
}
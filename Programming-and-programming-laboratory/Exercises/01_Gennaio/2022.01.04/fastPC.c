#include <stdio.h>

int contatore = 0;

int main(void)
{
    while (contatore <= 1000000000)
    {
        contatore++;
        if (contatore % 100000000 == 0)
        {
            printf("%d\n", contatore);
        }
    };
}
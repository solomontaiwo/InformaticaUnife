#include <stdio.h>

int valore = 3;
int contatore = 0;

int main(void)
{
    printf("A\tA+2\tA+4\tA+6\n\n");
    do
    {
        printf("%d\t%d\t%d\t%d\n", valore, valore + 2, valore + 4, valore + 6);
        contatore++;
        valore += 3;
    } while (contatore < 5);
}
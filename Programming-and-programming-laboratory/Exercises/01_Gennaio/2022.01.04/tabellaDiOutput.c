#include <stdio.h>

int valore = 1;
int n;

int main(void)
{
    printf("N\t10*N\t100*M\t1000*N\n\n");
    do
    {
        printf("%d\t%d\t%d\t%d\n", valore, valore * 10, valore * 100, valore * 1000);

        valore++;

    } while (valore <= 10);
}
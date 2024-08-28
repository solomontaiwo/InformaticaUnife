#include <stdio.h>

int main(int argc, char *argv[])
{
    int raggio;
    float PI = 3.142;
    float area;
    float circonferenza;

    // area del cerchio = PI * raggio^2
    // circonferenza del cerchio = 2 * PI * r

    printf("Inserisci il raggio del cerchio: ");
    scanf("%d", &raggio);

    area = (raggio * raggio) * PI;
    circonferenza = 2 * PI * raggio;

    printf("Area: %.3f\nCirconferenza: %.3f\n", area, circonferenza);
}
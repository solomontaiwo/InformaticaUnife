#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(float *primo, float *secondo);

int main(int argc, char *argv[])
{
    float numeriReali[50];
    int i = 0;
    int m;
    int conta = 0;

    printf("Inserisci dei numeri (negativo termina l'input): \n");
    for (int i = 0; i <= 50; i++)
    {
        conta++;

        scanf("%f", &numeriReali[i]);

        if (numeriReali[i] < 0)
            break;

        else
            for (int passaggio = 0; passaggio < conta; passaggio++)
            {
                for (m = 0; m < conta - 1; m++)
                    if (numeriReali[m] > numeriReali[m + 1])
                    {
                        swap(&numeriReali[m], &numeriReali[m + 1]);
                    }
            }
    }

    for (int k = 0; k < conta - 1; k++)
        printf("%.2f ", numeriReali[k]);
    puts("");

    return 0;
}

void swap(float *primo, float *secondo)
{
    float temp = *primo;
    *primo = *secondo;
    *secondo = temp;
}
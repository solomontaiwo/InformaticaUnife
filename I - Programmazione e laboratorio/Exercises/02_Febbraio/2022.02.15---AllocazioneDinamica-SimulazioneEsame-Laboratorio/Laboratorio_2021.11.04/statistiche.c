#include <stdio.h>
#define DIM 100

int main(int argc, char *argv[])
{
    int numero, massimo;
    float contatore = 0;
    float somma = 0;
    int minimo;

    while (contatore < DIM)
    {
        scanf("%d", &numero);

        if (numero < 0)
            break;
        else
        {
            if (numero < minimo)
            {
                minimo = numero;
            }
            if (massimo < numero)
            {
                massimo = numero;
            }

            somma += numero;
            contatore++;
        }
    }

    float media = somma / contatore;

    printf("Minimo: %d\n", minimo);
    printf("Massimo: %d\n", massimo);
    printf("Media aritmetica: %.2f\n", media);
}
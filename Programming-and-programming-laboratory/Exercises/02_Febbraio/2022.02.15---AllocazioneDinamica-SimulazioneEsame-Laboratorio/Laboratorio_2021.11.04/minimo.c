#include <stdio.h>
#define SIZE 5

int main(int argc, char *argv[])
{

    float array[SIZE];
    float valore;

    printf("Inserisci cinque valori: ");
    for (int i = 0; i < SIZE; i++)
        scanf("%f", &array[i]);

    // valore assoluto: n >= 0 -> n : -n

    float valoreAssoluto[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] >= 0)
            valoreAssoluto[i] = array[i];
        else
            valoreAssoluto[i] = -(array[i]);
    }

    float minimo = valoreAssoluto[0];

    for (int i = 0; i < SIZE; i++)
    {
        if (valoreAssoluto[i] < minimo)
            minimo = valoreAssoluto[i];
    }

    printf("%.1f\n", minimo);
}
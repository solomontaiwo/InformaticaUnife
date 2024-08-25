#include <stdio.h>

int main(int argc, char *argv[])
{
    int array[10], somma = 0;

    printf("Inserisci dieci valori: ");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &array[i]);
        somma = somma + array[i];
    }

    printf("La somma dei valori all'interno dell'array e' pari a %d.\n", somma);
}
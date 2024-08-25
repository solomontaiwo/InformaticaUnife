#include <stdio.h>
#include "funzioneGrandeArray.h"

int main(int argc, char *argv[])
{

    int array[10], massimo;

    printf("Inserisci dieci valori: ");

    for (int i = 0; i < 10; i++)
        scanf("%d", &array[i]);

    massimo = grandeArray(array);

    printf("Il valore piu' grande all'interno dell'array e' pari a %d.\n", massimo);

    return 0;
}
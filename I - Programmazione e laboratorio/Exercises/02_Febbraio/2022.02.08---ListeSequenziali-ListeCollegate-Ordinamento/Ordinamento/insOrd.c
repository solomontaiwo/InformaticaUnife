#include <stdio.h>

void insOrd(int array[], int lunghezza);

int main()
{
    int numeri[5];

    for (int i = 0; i < 5; i++)
        scanf("%d", &numeri[i]);

    insOrd(numeri, 5);

    for (int i = 0; i < 5; i++)
        printf("%d ", numeri[i]);
    puts("");
}

void insOrd(int array[], int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
    {
        int posizioneElemento = i;
        int elemento = array[i];
        while (posizioneElemento > 0 && array[posizioneElemento - 1] > elemento)
        {
            array[posizioneElemento] = array[posizioneElemento - 1];
            posizioneElemento--;
        }
        array[posizioneElemento] = elemento;
    }
}
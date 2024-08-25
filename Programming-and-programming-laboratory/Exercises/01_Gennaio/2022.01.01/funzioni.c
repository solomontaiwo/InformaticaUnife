#include <stdio.h>
#include <stdlib.h>

int addizioneNumeri(int a, int b)
{
    return a + b;
}

int main()
{
    int somma = addizioneNumeri(4, 60);
    printf("%d \n", somma);

    return 0;
}
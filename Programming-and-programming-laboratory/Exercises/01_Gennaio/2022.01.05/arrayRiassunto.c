#include <stdio.h>
#define risposteSize 40
#define frequenzaSize 11

int main(void)
{
    int frequenza[frequenzaSize] = {0};
    int risposte[risposteSize] = {1, 2, 6, 4, 8, 5, 9, 7, 8, 10, 1, 6, 3, 8, 6, 10, 3, 8, 2, 7, 6, 5, 7, 6, 8, 6, 7, 5, 6, 6, 5, 6, 7, 5, 6, 4, 8, 6, 8, 10};

    for (int risposta = 0; risposta < risposteSize; risposta++)
    {
        frequenza[risposte[risposta]]++;
    }

    printf("%s%20s\n", "Rating", "Frequenza");

    for (int rating = 1; rating < frequenzaSize; rating++)
    {
        printf("%6d%20d\n", rating, frequenza[rating]);
    }
}
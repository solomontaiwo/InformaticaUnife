// Leggere da tastiera una stringa e dire qual è la sua lunghezza //
#include <stdio.h>

int main(void)
{
    int i = 0;
    char stringa[100];

    printf("Inserisci una stringa, ti diro' quanti sono i caratteri al suo interno: ");

    scanf("%s", stringa);

    while (stringa[i] != '\0')
    {
        i++;
    }

    printf("I caratteri all'interno di '%s', includendo il terminatore, sono %d.\n", stringa, i);
}
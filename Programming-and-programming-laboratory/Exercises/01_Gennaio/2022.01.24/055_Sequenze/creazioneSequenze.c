/* 1 Scrivere un ciclo la cui variabile di controllo assuma tutti i valori compresi fra 1 e
10.
2 Scrivere un ciclo la cui variabile di controllo assuma decrescendo tutti i valori
compresi fra 10 e 5.
*/

#include <stdio.h>

int main()
{

    for (int i = 1; i <= 10; i++)
    {
        printf("%d ", i);
    }
    puts("");

    for (int i = 10; i >= 5; i--)
    {
        printf("%d ", i);
    }
    puts("");
}
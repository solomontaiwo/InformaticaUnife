// Scrivere un programma che simuli 10 lanci di un dado a 6 facce (cioè stampi 10 numeri casuali compresi fra 1 e 6). //
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", 1 + rand() % 6);
    }
    return 0;
}
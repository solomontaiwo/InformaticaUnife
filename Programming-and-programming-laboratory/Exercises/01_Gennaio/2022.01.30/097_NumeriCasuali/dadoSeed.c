// generazione numeri casuali ad ogni esecuzione (con funzione seed e time) //
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", 1 + rand() % (100 - 1 + 1));
    }
}
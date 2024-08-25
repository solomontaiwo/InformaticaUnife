// Scrivere un programma che stampi 5 righe di 20 asterischi. In particolare, definire una funzione di nome star che stampi 20 asterischi con un ciclo for, e chiamarla 5 volte con un ciclo for. //
#include <stdio.h>

char star()
{
    for (int i = 0; i < 20; i++)
    {
        printf("*");
    }
    puts("");
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        star();
    }
}
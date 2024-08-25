// Scrivere un programma che richieda all’utente 10 numeri e li stampi dal più piccolo al più grande. //
#include <stdio.h>
#define SIZE 10

int main(void)
{
    int array[SIZE], m, dl, i, j;

    for (dl = 0; dl < SIZE; dl++)
    {
        scanf("%d", m);
        j = dl;
        while (j > 0 && m < array[j - 1])
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = m;
    }
    for (i = 0; i < dl; i++)
    {
        printf("%d ", array[i]);
        puts("");
    }
}
// Scrivere un programma che richieda all’utente cinque numeri interi e li stampi in ordine inverso. Ad esempio, se l’utente digita i numeri 5, 3, 7, 8 e 2, il programma deve stampare 28735. //
#include <stdio.h>

int main()
{
    int numeri[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &numeri[i]);
    }

    for (int i = 4; i >= 0; i--)
    {
        printf("%d ", numeri[i]);
    }
    puts("");
}
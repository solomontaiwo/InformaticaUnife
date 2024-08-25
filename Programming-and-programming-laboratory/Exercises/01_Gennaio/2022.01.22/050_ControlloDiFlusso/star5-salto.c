// Scrivere un programma che stampi a video cinque asterischi e poi vada a capo. //

#include <stdio.h>

int main()
{
    int i = 0;
    do
    {
        printf("*");
        i++;
    } while (i < 5);
    puts("");
}
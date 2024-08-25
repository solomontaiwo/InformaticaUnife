#include <stdio.h>

char *colori[] = {"Blu", "Giallo", "Verde", "Marrone", "Viola"};

int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%s ", colori[i]);
    }
    puts("");
}
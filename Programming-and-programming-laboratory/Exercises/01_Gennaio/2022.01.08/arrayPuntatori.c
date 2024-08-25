#include <stdio.h>

char const *kebab[5] = {"Cipolla", "Piccante", "Patatine", "Insalata", "Ketchup"};

int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%s ", kebab[i]);
    }
    puts("");
}
#include <stdio.h>

int i;
int j;

star()
{
    for (i = 0; i < 20; i++)
        printf("*");
    printf("\n");
}

main()
{
    for (j = 0; j < 5; j++)
        star();
}

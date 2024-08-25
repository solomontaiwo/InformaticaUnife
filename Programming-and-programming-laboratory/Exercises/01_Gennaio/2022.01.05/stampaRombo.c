#include <stdio.h>

int contatore = 0;

int main()
{
    printf("         *\n");

    printf("        ");
    for (int i = 1; i <= 3; i++)
    {
        printf("*");
    }
    printf("\n");

    printf("       ");
    for (int i = 1; i <= 5; i++)
    {
        printf("*");
    }
    printf("\n");

    printf("      ");
    for (int i = 1; i <= 7; i++)
    {
        printf("*");
    }
    printf("\n");

    printf("     ");
    for (int i = 1; i <= 9; i++)
    {
        printf("*");
    }
    printf("\n");

    // inizio triangolo discendente

    printf("      ");
    for (int i = 1; i <= 7; i++)
    {
        printf("*");
    }
    printf("\n");

    printf("       ");
    for (int i = 1; i <= 5; i++)
    {
        printf("*");
    }
    printf("\n");

    printf("        ");
    for (int i = 1; i <= 3; i++)
    {
        printf("*");
    }
    printf("\n");

    printf("         *\n");
}
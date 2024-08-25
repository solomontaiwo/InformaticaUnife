#include <stdio.h>
main()
{
    int N, i;
    int j;
    printf("Quante righe?\n");
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= i - 1; j++)
            printf(" ");

        for (j = 1; j <= 13 - 2 * (i - 1); j++)
            printf("*");
        printf("\n");
    }
}
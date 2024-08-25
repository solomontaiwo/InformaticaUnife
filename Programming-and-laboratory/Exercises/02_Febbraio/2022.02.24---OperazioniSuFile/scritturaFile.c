#include <stdio.h>
#include <stdlib.h>

int main(int argc, char argv[])
{
    FILE *pft;
    int numeri[10];

    if ((pft = fopen("NumeriCasuali.txt", "wt")) == NULL)
    {
        printf("Impossibile aprire il file");
        exit(1);
    }

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &numeri[i]);
        fprintf(pft, "%d ", numeri[i]);
    }

    fclose(pft);
    return 0;
}
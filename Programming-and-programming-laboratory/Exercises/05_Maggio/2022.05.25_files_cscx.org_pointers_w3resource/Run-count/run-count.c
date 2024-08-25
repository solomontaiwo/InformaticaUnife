#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int count = 1;
    FILE *pft;

    if ((pft = fopen("runcount.txt", "rt")) == NULL)
    {
        pft = fopen("runcount.txt", "wt");
        fprintf(pft, "%d", 1);
    }
    else
    {
        fscanf(pft, "%d", &count);
        fclose(pft);
        pft = fopen("runcount.txt", "wt");
        count++;
        fprintf(pft, "%d", count);
    }

    printf("run #%d\n", count);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char lettura[20];

    FILE *fp;

    if ((fp = fopen("silvia.txt", "rt")) == NULL)
        printf("Impossibile aprire il file.\n");
    else
        fscanf(fp, "%s", lettura);

    fclose(fp);

    printf("Di seguito il valore ripreso dal file di testo: %s.\n", lettura);
}
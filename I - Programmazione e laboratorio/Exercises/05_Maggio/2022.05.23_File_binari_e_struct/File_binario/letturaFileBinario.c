#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *pfb;
    char parola[10];

    if ((pfb = fopen("fileBinario", "rb")) == NULL)
    {
        printf("Impossibile leggere file binario.\n");
        exit(1);
    }

    while ((fscanf(pfb, "%s", parola)) != EOF)
        printf("%s", parola);

    puts("");

    fclose(pfb);
}
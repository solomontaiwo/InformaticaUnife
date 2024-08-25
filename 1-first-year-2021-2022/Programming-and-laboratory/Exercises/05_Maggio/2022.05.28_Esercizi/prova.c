#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    char parola[50];

    if ((pft = fopen("prova.txt", "wt")) == NULL)
    {
        printf("Impossibile creare il file prova.txt\n");
        exit(1);
    }

    scanf("%s", parola);

    while (strcmp(parola, "FINE") != 0)
    {
        fprintf(pft, "%s\n", parola);
        scanf("%s", parola);
    }

    fclose(pft);
    return 0;
}
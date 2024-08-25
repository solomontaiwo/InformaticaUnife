#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    char parola[10];

    if (argc != 2)
    {
        printf("Dare come argomento il nome del file da aprire.\n");
        exit(1);
    }

    if ((pft = fopen(argv[1], "rt")) == NULL)
    {
        printf("Impossibile aprire il file.\n");
        exit(2);
    }

    while (!feof(pft))
        fscanf(pft, "%s", &parola);

    printf("%s", parola);
    puts("");

    fclose(pft);
}
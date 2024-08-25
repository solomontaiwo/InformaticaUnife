#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    char lettera;

    if (argc != 2)
    {
        printf("Argomento errato.\n");
        exit(1);
    }

    if ((pft = fopen(argv[1], "rt")) == NULL)
    {
        printf("Impossibile leggere il file %s\n.", argv[1]);
        exit(2);
    }

    while ((fscanf(pft, "%c", &lettera)) != EOF)
    {
        printf("%c", lettera);
    }

    puts("");

    fclose(pft);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    char testo;

    if (argc != 2)
    {
        printf("Numero argomenti non valido. Scegliere file di testo corretto.\n");
        exit(1);
    }

    if ((pft = fopen(argv[1], "rt")) == NULL)
    {
        printf("Impossibile aprire file.\n");
        exit(2);
    }

    while ((testo = fgetc(pft)) != EOF)
    {
        printf("%c", testo);
    }
    puts("");

    fclose(pft);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char parola;
    FILE *testo;

    if (argc != 2)
    {
        printf("Uso improprio del programma.\n");
        exit(1);
    }

    if ((testo = fopen(argv[1], "rt")) == NULL)
    {
        printf("Impossibile aprire il file.\n");
        exit(2);
    }

    while ((parola = fgetc(testo)) != EOF)
    {
        printf("%c", parola);
    }
    puts("");
    
    fclose(testo);
    return 0;
}
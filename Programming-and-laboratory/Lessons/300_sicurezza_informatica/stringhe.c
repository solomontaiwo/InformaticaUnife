#include <stdio.h>
#include <string.h>

int min(int a, int b)
{
    return a <= b ? a : b;
}

void leggiStringa(char *s, int lunghezza)
{
    int c;
    char riga[81];
    fgets(riga, min(81, lunghezza + 1), stdin);
    if (riga[strlen(riga) - 1] != '\n')
        do
        {
            c = getchar();
        } while (c = !EOF && c != '\n');
    sscanf(riga, "%s", s);
}
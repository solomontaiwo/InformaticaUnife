#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char lettera_minuscola_casuale()
{
    return 97 + rand() % (122 - 97 + 1);
}

int main(int argc, char *argv[])
{
    char s[37] = "https://meet.google.com/";

    srand(time(NULL));

    s[24] = lettera_minuscola_casuale();
    s[25] = lettera_minuscola_casuale();
    s[26] = lettera_minuscola_casuale();
    s[27] = '-';
    s[28] = lettera_minuscola_casuale();
    s[29] = lettera_minuscola_casuale();
    s[30] = lettera_minuscola_casuale();
    s[31] = lettera_minuscola_casuale();
    s[32] = '-';
    s[33] = lettera_minuscola_casuale();
    s[34] = lettera_minuscola_casuale();
    s[35] = lettera_minuscola_casuale();
    s[36] = '\0';

    printf("%s\n", s);
}
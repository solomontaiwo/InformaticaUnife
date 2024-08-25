#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char info[100];
    char ufficio[] = "HR";
    int dipendenti = 75;

    sprintf(info, "L'ufficio %s ha %d dipendenti.", ufficio, dipendenti);
    printf("%s\n", info);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char info[] = "Mantova Lombardia 500000";
    char citta[50];
    char regione[50];
    int popolazione;

    sscanf(info, "%s %s %d", citta, regione, &popolazione);
    printf("%d vivono a %s, %s.\n", popolazione, citta, regione);

    return 0;
}
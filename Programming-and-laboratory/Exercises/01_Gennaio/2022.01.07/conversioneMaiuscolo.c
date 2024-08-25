#include <stdio.h>
#include <ctype.h>

void conversioneMaiuscolo(char *ptrs);
int main(void)
{

    char stringa[] = "caRatteri e $32.98";

    printf("Stringa prima della conversione: %s", stringa);
    conversioneMaiuscolo(stringa);
    printf("\nStringa dopo la conversione: %s\n", stringa);
}

void conversioneMaiuscolo(char *ptrs)
{
    while (*ptrs != '\0')
    {
        *ptrs = toupper(*ptrs);
        ptrs++;
    }
}
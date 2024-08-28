#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *allocaStringa(int n)
{
    char *s;
    s = (char *)malloc(n);
    if (s == NULL)
    {
        printf("Impossibile allocare la stringa.\n");
        exit(1);
    }
    return s;
}

void libera(char *s)
{
    free(s);
}

int main()
{
    char *pc = allocaStringa(100);
    strcpy(pc, "Ferrara");
    printf("%s\n", pc);
    libera(pc);
    return 0;
}
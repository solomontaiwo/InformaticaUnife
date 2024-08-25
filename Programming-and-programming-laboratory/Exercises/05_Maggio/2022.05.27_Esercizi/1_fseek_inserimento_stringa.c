#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    if ((pft = fopen("file_new.txt", "wt")) == NULL)
    {
        printf("Impossibile creare il file di testo.\n");
        exit(1);
    }
    else
    {
        fputs("Yes, we are learning fseek function in C", pft);
        fseek(pft, 12, SEEK_SET);
        fputs("trying to insert something in between", pft);
        fclose(pft);
    }
    return 0;
}
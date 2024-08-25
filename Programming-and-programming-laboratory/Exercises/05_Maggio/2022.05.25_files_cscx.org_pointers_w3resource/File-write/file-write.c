#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    char stringa[50];

    if ((pft = fopen("message.txt", "wt")) == NULL)
    {
        printf("Can't create text file.\n");
        exit(1);
    }

    fprintf(pft, "%s", "Hello file system.\n");
    printf("Created text file message.txt\n");

    return 0;
}
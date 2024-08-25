#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    char nome[60];

    if ((pft = fopen("name.txt", "rt")) == NULL)
    {
        printf("name.txt: file not found.\n");
        exit(1);
    }

    fscanf(pft, "%s", nome);

    printf("%s\n", nome);

    return 0;
}
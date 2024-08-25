#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pf;
    char nome[20];

    if ((pf = fopen("nome.txt", "rt")) == NULL)
    {
        printf("Impossibile aprire il file di testo.\n");
        exit(1);
    }

    fscanf(pf, "%s", nome);
    printf("%s\n", nome);

    if (fclose(pf) != 0)
    {
        printf("Impossibile chiudere il file di testo.\n");
        exit(2);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pf;
    char nome[20];

    if ((pf = fopen("nome.dat", "rb")) == NULL)
    {
        printf("Impossibile aprire il file binario.\n");
        exit(1);
    }

    fread(nome, sizeof(nome), 1, pf);

    printf("%s\n", nome);

    if (fclose(pf) != 0)
    {
        printf("Impossibile chiudere il file binario.\n");
        exit(1);
    }
    return 0;
}
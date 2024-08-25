#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *pf;
    char nome[20];

    printf("Inserisci un nome.\n");
    scanf("%s", nome);

    if ((pf = fopen("nome.dat", "wb")) == NULL)
    {
        printf("Immpossibile aprire il file binario.\n");
        exit(1);
    }

    fwrite(&nome, sizeof(char), 1, pf);

    if (fclose(pf) != 0)
    {
        printf("Impossibile chiudere il file binario.\n");
        exit(2);
    }
    return 0;
}
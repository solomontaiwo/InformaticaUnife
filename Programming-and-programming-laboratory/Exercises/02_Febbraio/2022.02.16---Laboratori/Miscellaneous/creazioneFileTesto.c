#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    char nome[20];
    FILE *pf;

    printf("Inserisci un nome\n");
    scanf("%s", nome);

    if ((pf = fopen("nome.txt", "wt")) == NULL)
    {
        printf("Impossibile aprire il file.\n");
        exit(1);
    }

    fprintf(pf, "%s", nome);

    if (fclose(pf) != 0)
    {
        printf("Impossibile chiudere il file di testo.\n");
        exit(2);
    }
    return 0;
}

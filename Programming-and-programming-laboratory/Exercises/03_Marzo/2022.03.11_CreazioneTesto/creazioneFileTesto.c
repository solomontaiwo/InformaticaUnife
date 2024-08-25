#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    char parola[10];

    if ((pft = fopen("testo.txt", "wt")) == NULL)
    {
        printf("Impossibile aprire il file di testo.\n");
        exit(1);
    }

    printf("Inserisci una parola: ");
    scanf("%s", parola);

    fprintf(pft, "%s", parola);

    fclose(pft);
    return 0;
}
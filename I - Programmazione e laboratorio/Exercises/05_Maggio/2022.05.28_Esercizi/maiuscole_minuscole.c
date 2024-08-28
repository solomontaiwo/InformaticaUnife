#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    char nomeFile[20];

    printf("Inserisci il nome del file di testo: ");
    scanf("%s", nomeFile);
    char carattere;
    char input[250];

    if ((pft = fopen(nomeFile, "wt")) == NULL)
    {
        printf("Impossibile creare il file di testo %s.\n", nomeFile);
        exit(1);
    }

    scanf(" %[^\n]", input);
    fprintf(pft, "%s", input);

    fclose(pft);
    pft = fopen(nomeFile, "rt");

    while ((fscanf(pft, "%c", &carattere)) != EOF)
    {
        carattere = tolower(carattere);
        printf("%c", carattere);
    }

    puts("");
    fclose(pft);
    return 0;
}
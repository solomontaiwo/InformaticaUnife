// Si mostri a video il contenuto di un file di testo il cui nome viene inserito da tastiera. //
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

char carattere;
char nomeFile[SIZE];

int main(void)
{
    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", nomeFile);

    FILE *fp;

    if (fp = fopen(nomeFile, "rt"))
    {
        while (fscanf(fp, "%c", &carattere) == 1)
        {
            printf("%c", carattere);
        }
        puts("");
        fclose(fp);
    }
    else
        printf("Il file non e' stato trovato.\n");
}
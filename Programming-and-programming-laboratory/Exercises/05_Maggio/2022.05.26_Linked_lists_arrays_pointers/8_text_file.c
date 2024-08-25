#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    char stringa[40], nuovaStringa[40];
    char risposta[10];
    int i = 0;

    if ((pft = fopen("testo_generico.txt", "wt")) == NULL)
    {
        printf("Impossibile creare il file di testo!\n");
        exit(1);
    }

    printf("Inserisci una stringa: ");
    fgets(stringa, sizeof(stringa), stdin);
    fprintf(pft, "%s", stringa);

    printf("Chiusura file...\n");
    fclose(pft);

    printf("Vuoi aggiungere altro al documento?\n- ");
    scanf("%s", risposta);

    getchar();

    if ((strcmp(risposta, "Si'")) == 0)
    {
        if ((pft = fopen("testo_generico.txt", "at")) == NULL)
        {
            printf("Impossibile aprire il file di testo.\n");
            exit(2);
        }

        // getchar();

        printf("Inserisci la stringa che vuoi aggiungere al file: ");
        fgets(nuovaStringa, sizeof(stringa), stdin);
        fprintf(pft, "%s", nuovaStringa);

        printf("Chiusura del file e del programma in corso...\n");
    }
    else
        printf("Programma terminato.\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main(int argc, char *argv[])
{

    char nomeProgramma[SIZE];
    char testoDaInserire[SIZE];
    FILE *pft;

    printf("Inserisci il nome del file di testo (con estensione .txt) che vuoi creare: ");
    scanf("%[^\n]s", nomeProgramma);

    if ((pft = fopen(nomeProgramma, "wt")) == NULL)
    {
        puts("Impossibile creare il file di testo, il programma verra' terminato.");
        exit(1);
    }

    printf("Inserisci il testo che vuoi inserire nel file: ");

    scanf(" %100[^\n]s", testoDaInserire);

    fprintf(pft, "%s", testoDaInserire);

    fclose(pft);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

int main(int argc, char *argv[])
{

    FILE *pft;
    char nome[SIZE];
    char nomeGiusto[SIZE];

    if (argc != 2)
    {
        puts("Argomento mancante o errato. Il programma verra' chiuso.");
        exit(1);
    }

    if ((pft = fopen(argv[1], "rt")) == NULL)
    {
        puts("Impossibile aprire il file di testo impostato come argomento.");
        exit(2);
    }

    printf("Inserisci il tuo nome e cognome: ");
    scanf("%[^\n]", nomeGiusto);
    // fgets(nome, sizeof(nome), stdin);

    while ((fgets(nome, SIZE, pft)) != NULL)
    {
        if ((strcmp(nome, nomeGiusto)) == 0)
        {
            printf("Il nome all'interno del testo corrisponde!\n");
        }
        else
            printf("Nome non corrispondente.\n");
    }
}
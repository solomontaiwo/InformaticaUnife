#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

struct nodo
{
    char nomeCognome[SIZE];
    int giornoNascita, meseNascita, annoNascita;
    struct nodo *nodoSuccessivo;
};

int main(int argc, char *argv[])
{
    FILE *pft;
    int numeroIscritti;
    char nomeFile[SIZE];

    printf("\nQuanti iscritti ci sono in palestra? ");
    scanf("%d", &numeroIscritti);

    struct nodo *iscritti; // testa nodo
    struct nodo *corrente;

    iscritti = (struct nodo *)malloc(sizeof(struct nodo));

    printf("\nDai un nome al file di testo in cui inserire i dati: ");
    scanf("%s", nomeFile);

    getchar();

    if ((pft = fopen(nomeFile, "wt")) == NULL)
    {
        printf("Impossibile creare il file di testo.\n");
        exit(1);
    }

    printf("\nInserisci il nome e cognome dell'iscritto #1: ");
    scanf("%[^\n]", iscritti->nomeCognome);

    printf("Inserisci la data di nascita dell'iscritto #1: ");
    scanf("%d/%d/%d", &iscritti->giornoNascita, &iscritti->meseNascita, &iscritti->annoNascita);

    getchar();

    fprintf(pft, "%s: %d/%.2d/%d\n", iscritti->nomeCognome, iscritti->giornoNascita, iscritti->meseNascita, iscritti->annoNascita);

    if (numeroIscritti == 1)
    {
        iscritti->nodoSuccessivo = NULL;
    }
    else
    {
        iscritti->nodoSuccessivo = corrente;
        for (int i = 1; i < numeroIscritti; i++)
        {
            corrente = (struct nodo *)malloc(sizeof(struct nodo));
            printf("\nInserisci il nome e cognome dell'iscritto #%d: ", i + 1);
            scanf("%[^\n]", corrente->nomeCognome);

            printf("Inserisci la data di nascita dell'iscritto #%d: ", i + 1);
            scanf("%d/%d/%d", &corrente->giornoNascita, &corrente->meseNascita, &corrente->annoNascita);

            fprintf(pft, "%s: %d/%.2d/%d\n", corrente->nomeCognome, corrente->giornoNascita, corrente->meseNascita, corrente->annoNascita);
            getchar();
            corrente->nodoSuccessivo = corrente;
        }
        corrente->nodoSuccessivo = NULL;
    }

    printf("\nScrittura dei dati nel file %s...\n", nomeFile);

    printf("Chiusura file e programma...\n");

    free(iscritti);
    free(corrente);
    fclose(pft);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

struct nodo
{
    char nomeCognome[SIZE];
    int numeroMatricola;
    int annoImmatricolazione;
    float mediaEsami;
    struct nodo *nodoSuccessivo;
};

int main(int argc, char *argv[])
{
    int numeroStudenti, i, lunghezza;

    struct nodo *testa = (struct nodo *)malloc(sizeof(struct nodo));

    printf("Inserisci il numero di studenti che vuoi catalogare: ");
    scanf("%d", &numeroStudenti);

    printf("Inserisci nome e cognome studente: ");
    scanf("%s", testa->nomeCognome);

    printf("Inserisci numero matricola: ");
    scanf("%d", &testa->numeroMatricola);

    printf("Inserisci anno immatricolazione: ");
    scanf("%d", &testa->annoImmatricolazione);

    printf("Inserisci media esami: ");
    scanf("%f", &testa->mediaEsami);

    testa->nodoSuccessivo = NULL;
    struct nodo *corrente = testa;

    for (i = 1; i < numeroStudenti; i++)
    {
        corrente->nodoSuccessivo = (struct nodo *)malloc(sizeof(struct nodo));
        corrente = corrente->nodoSuccessivo;

        printf("Inserisci nome e cognome studente: ");
        scanf("%s", corrente->nomeCognome);
        printf("Inserisci numero matricola: ");
        scanf("%d", &corrente->numeroMatricola);
        printf("Inserisci anno immatricolazione: ");
        scanf("%d", &corrente->annoImmatricolazione);
        printf("Inserisci media esami: ");
        scanf("%f", &corrente->mediaEsami);

        corrente->nodoSuccessivo = NULL;
    }

    corrente->nodoSuccessivo = testa;

    printf("\nNome e cognome studente: ");
    printf("%s", testa->nomeCognome);
    printf("Numero matricola: %d\n", testa->numeroMatricola);
    printf("Anno immatricolazione: %d\n", testa->annoImmatricolazione);
    printf("Media esami: %.2f\n", testa->mediaEsami);

    i = 1;

    while (i < numeroStudenti)
    {
        printf("\nNome e cognome studente: %s\n", corrente->nomeCognome);
        printf("Numero matricola: %d\n", corrente->numeroMatricola);
        printf("Anno immatricolazione: %d\n", corrente->annoImmatricolazione);
        printf("Media esami: %.2f\n", corrente->mediaEsami);
        corrente = corrente->nodoSuccessivo;
        i++;
    }

    testa = corrente;

    free(testa);

    return 0;
}
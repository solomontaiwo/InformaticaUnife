#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int dato;
    struct nodo *nodoSuccessivo;
};

int main(int argc, char *argv[])
{
    int numeroListe, i = 0;

    printf("Inserisci il numero di liste che vuoi: ");
    scanf("%d", &numeroListe);

    struct nodo *testa;
    struct nodo *listaCorrente;

    testa = (struct nodo *)malloc(sizeof(struct nodo));
    printf("Inserisci i dati per la lista #1: \n");
    scanf("%d", &testa->dato);

    if (numeroListe > 1)
    {
        listaCorrente = (struct nodo *)malloc(sizeof(struct nodo));
        testa->nodoSuccessivo = listaCorrente;
    }
    else
    {
        testa->nodoSuccessivo = NULL;
    }

    for (i = 1; i < numeroListe; i++)
    {
        printf("Inserisci i dati per la lista #%d: \n", i + 1);
        scanf("%d", &listaCorrente->dato);
        if (i == (numeroListe - 1))
        {
            listaCorrente->nodoSuccessivo = NULL;
        }
        else
        {
            listaCorrente = (struct nodo *)malloc(sizeof(struct nodo));
            listaCorrente->nodoSuccessivo = listaCorrente;
        }
    }

    puts("Dati inseriti nelle liste: ");

    printf("Dato lista #1: %d\n", testa->dato);

    testa->nodoSuccessivo = listaCorrente;

    for (i = 1; i <= numeroListe; i++)
    {
        printf("Dato lista #%d: %d\n", i + 1, listaCorrente->dato);
        listaCorrente = listaCorrente->nodoSuccessivo;
    }

    listaCorrente->nodoSuccessivo = NULL;

    free(testa);
    free(listaCorrente);
    return 0;
}
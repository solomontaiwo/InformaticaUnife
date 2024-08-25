#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int dato;
    struct nodo *successivo;
};

int main(int argc, char *argv[])
{
    int numero, i;
    printf("Inserisci il numero di liste: ");
    scanf("%d", &numero);

    struct nodo *testa;
    testa = (struct nodo *)malloc(sizeof(struct nodo));
    printf("Inserisci un valore: ");
    scanf("%d", &testa->dato);
    testa->successivo = NULL;
    struct nodo *corrente = testa;

    for (i = 1; i < numero; i++)
    {
        corrente->successivo = (struct nodo *)malloc(sizeof(struct nodo));
        corrente = corrente->successivo;
        printf("Inserisci un valore: ");
        scanf("%d", &corrente->dato);
        corrente->successivo = NULL;
    }

    corrente = testa;

    for (i = 0; corrente; corrente = corrente->successivo)
        printf("Il nodo %d contiene un valore di %d.\n", i++, corrente->dato);
}
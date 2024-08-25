#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 20

struct nodo
{
    char nome[SIZE];
    struct nodo *nodoSuccessivo;
};

int main(int argc, char *argv[])
{
    struct nodo *lista;
    lista = (struct nodo *)malloc(sizeof(struct nodo));
    lista->nodoSuccessivo = NULL;

    printf("Inserisci un nome: ");
    scanf("%s", lista->nome);

    printf("Nome inserito nella struttura: %s\n", lista->nome);

    return 0;
}
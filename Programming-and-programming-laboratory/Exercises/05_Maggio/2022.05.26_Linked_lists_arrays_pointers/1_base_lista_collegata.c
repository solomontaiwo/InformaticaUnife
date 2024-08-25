#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int dato;
    struct nodo *nodoSuccessivo;
};

int main(int argc, char *argv[])
{
    struct nodo *lista;
    lista = (struct nodo *)malloc(sizeof(struct nodo));
    printf("Inserisci un numero: ");
    scanf("%d", &lista->dato);
    lista->nodoSuccessivo = NULL;

    printf("\nDato inserito all'interno della lista: %d\n", lista->dato);

    free(lista);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void inserimentoTesta(Lista *pl, int numero)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    if (aux == NULL)
        exit(100);
    aux->dato = numero;
    aux->next = *pl;
    (*pl) = aux;
}

void insNonOrdinato(Lista *pl, int valori)
{
    int array[] = {4, 6, 10, 8};
    int i;
    for (i = 0; i < valori; i++)
    {
        (*pl) = (Nodo *)malloc(sizeof(Nodo));
        (*pl)->dato = array[i];
        (*pl)->next = NULL;
        pl = &(*pl)->next;
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d ", l->dato);
        l = l->next;
    }
    puts("");
}

int main(int argc, char *argv[])
{

    Lista ciao;

    insNonOrdinato(&ciao, 4);

    stampa(ciao);

    inserimentoTesta(&ciao, 3);

    stampa(ciao);
}
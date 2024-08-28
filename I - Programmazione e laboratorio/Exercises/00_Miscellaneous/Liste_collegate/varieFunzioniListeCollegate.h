#include <stdio.h>
#include <stdlib.h>

typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

int piena(Lista l)
{
    return 0; // una lista collegata non puo' mai essere piena
}

int vuota(Lista l)
{
    return l == NULL;
}

void stampa(Lista l)
{
    while (l != NULL) // oppure while (l)
    {
        printf("%d ", l->dato);
        l = l->next;
    }
    puts("");
}

void listaNonOrdinata(Lista *pl, int numero)
{
    int elementi[] = {5, 9, 1, 4, 6, 7, 10, 77, 8};
    int i;
    for (i = 0; i < numero; i++)
    {
        (*pl) = (Nodo *)malloc(sizeof(Nodo));
        (*pl)->dato = elementi[i];
        (*pl)->next = NULL;
        pl = &(*pl)->next;
    }
}

void azzera(Lista l)
{
    while (l)
    {
        l->dato = 0;
        l = l->next;
    }
}

void elimTesta(Lista *pl);
void nuovaLista(Lista *pl);
Lista *ricerca(Lista *pl, int numero);
Lista *ricercaPerInsOrd(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
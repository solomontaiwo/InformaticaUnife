/* Scrivere una funzione di prototipo void reverse(Lista l1, Lista *pl2) che faccia sì che *pl2 diventi la lista inversa di l1, cioè contenga gli stessi elementi ma in ordine inverso.
Ad esempio, l’inversa di [2,0,4,3] è [3,4,0,2]. E’ sufficiente:
- inizializzare *pl2;
- inserire in testa a *pl2 gli elementi di *pl1, dal primo all’ultimo.
*/

#include <stdlib.h>
#include <stdio.h>

typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void listaNonOrdinata(Lista *pl, int numeroElementi)
{
    int array[] = {2, 0, 4, 3};
    int i;
    for (i = 0; i < numeroElementi; i++)
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

void insTesta(Lista *pl, int numero)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    if (aux == NULL)
        exit(100);
    aux->dato = numero;
    aux->next = *pl;
    *pl = aux;
}

int lunghezza(Lista l)
{
    int c = 0;
    while (l)
    {
        c++;
        l = l->next;
    }
    return c;
}

void reverse(Lista l1, Lista *pl2) // *pl2 diventi la lista inversa di l1, cioè contenga gli stessi elementi ma in ordine inverso
{
    while (l1)
    {
        insTesta(pl2, l1->dato);
        l1 = l1->next;
    }
}

int main(int argc, char *argv[])
{
    Lista prima, seconda;

    listaNonOrdinata(&seconda, 4);
    stampa(seconda);

    reverse(&prima, seconda);
    stampa(prima);
}
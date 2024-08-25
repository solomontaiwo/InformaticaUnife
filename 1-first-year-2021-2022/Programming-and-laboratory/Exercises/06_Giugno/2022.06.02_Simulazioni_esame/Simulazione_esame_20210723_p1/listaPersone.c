#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaPersone.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Dato d)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->dato = d;
    aux->next = *pl;
    *pl = aux;
}

void aggiorna(Lista *pl, Record r, Data oggi)
{
    while (*pl != NULL && strcmp((*pl)->dato.CF, r.CF) < 0)
        pl = &(*pl)->next;

    if (*pl == NULL || strcmp((*pl)->dato.CF, r.CF) != 0)
    {
        Dato d;
        strcpy(d.CF, r.CF);
        d.tampone = 0;
        d.vaccino = 0;
        insTesta(pl, d);
    }
    if (r.evento == 'V')
        (*pl)->dato.vaccino = 1;
    else if (r.evento == 'T')
        (*pl)->dato.tampone = 1;
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s ", l->dato.CF);
        if (l->dato.vaccino)
            printf("vaccino ");
        if (l->dato.tampone)
            printf("tampone ");
        printf("\n");
        l = l->next;
    }
}
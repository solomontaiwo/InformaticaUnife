#include <stdlib.h>
#include <stdio.h>
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

void aggiorna(Lista *pl, Record r)
{
    Dato d;
    while (*pl != NULL && strcmp((*pl)->dato.CF, r.CF) < 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->dato.CF, r.CF) == 0)
    {
        if (r.evento == 'V')
            (*pl)->dato.vaccino = 1;
        else if (r.evento == 'T')
            (*pl)->dato.tampone = 1;
    }
    else
    {
        Dato d;
        strcpy(d.CF, r.CF);
        if (r.evento == 'V')
            d.vaccino = 1;
        else
            d.vaccino = 0;
        if (r.evento == 'T')
            d.tampone = 1;
        else
            d.tampone = 0;

        insTesta(pl, d);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s %c %c", l->dato.CF);
        if (l->dato.vaccino)
            printf("vaccino ");
        if (l->dato.tampone)
            printf("tampone ");
        printf("\n");
        l = l->next;
    }
}
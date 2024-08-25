#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUtenti.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Dato d)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    testa->d = d;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Record r)
{
    while (*pl != NULL)
        pl = &(*pl)->next;

    while (*pl == NULL)
    {
        Dato d;
        strcpy(d.numero, r.numero);
        d.credito = r.credito;
        insTesta(pl, d);
    }
}


void stampa(Lista l)
{
    while (l)
    {
        printf("%s %.2f\n", l->d.numero, l->d.credito);
        l = l->next;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUtenti.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, DatoLista d)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    testa->d = d;
    testa->next = *pl;
    *pl = testa;
}

void aggiornaLista(Lista *pl, Record r)
{
    while (*pl != NULL)
        pl = &(*pl)->next;

    if (*pl == NULL)
    {
        DatoLista d;
        strcpy(d.numero, r.numero);
        d.residuo = r.credito;
        d.piano = r.piano;
        insTesta(pl, d);
    }
}

void stampaLista(Lista l)
{
    while (l)
    {
        printf("%s %.2f\n", l->d.numero, l->d.residuo);
        l = l->next;
    }
}
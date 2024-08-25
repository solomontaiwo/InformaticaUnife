#include <stdio.h>
#include <stdlib.h>

#include "listaGiornate.h"

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
    while (*pl != NULL && (*pl)->d.giorno != r.giorno && (*pl)->d.mese != r.mese)
        pl = &(*pl)->next;

    if (*pl != NULL && (*pl)->d.giorno == r.giorno && (*pl)->d.mese == r.mese)
    {
        (*pl)->d.ore += r.ore;
    }

    if (*pl == NULL)
    {
        Dato d;
        d.giorno = r.giorno;
        d.mese = r.mese;
        d.ore = r.ore;
        insTesta(pl, d);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d/%d %.2f\n", l->d.giorno, l->d.mese, l->d.ore);
        l = l->next;
    }
}
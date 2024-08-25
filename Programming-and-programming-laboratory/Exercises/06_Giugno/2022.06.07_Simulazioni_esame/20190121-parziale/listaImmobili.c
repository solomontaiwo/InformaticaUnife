#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaImmobili.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Immobile imm)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    testa->imm.distanza = imm.distanza;
    testa->imm.vani = imm.vani;
    strcpy(testa->imm.indirizzo, imm.indirizzo);
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Record r)
{
    while (*pl != NULL && (*pl)->imm.distanza < r.distanza)
        pl = &(*pl)->next;

    if (*pl != NULL && (*pl)->imm.distanza > r.distanza)
    {
        Immobile i;
        i.distanza = r.distanza;
        strcpy(i.indirizzo, r.indirizzo);
        i.vani = r.vani;
        insTesta(pl, i);
    }

    if (*pl == NULL)
    {
        Immobile i;
        i.distanza = r.distanza;
        strcpy(i.indirizzo, r.indirizzo);
        i.vani = r.vani;
        insTesta(pl, i);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s %d %.3f\n", l->imm.indirizzo, l->imm.vani, l->imm.distanza);
        l = l->next;
    }
}
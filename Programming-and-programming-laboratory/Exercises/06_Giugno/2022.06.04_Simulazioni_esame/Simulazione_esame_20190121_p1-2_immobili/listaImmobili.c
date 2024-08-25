#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaImmobili.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void instesta(Lista *pl, Immobile imm)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    testa->imm = imm;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Immobile imm)
{
    while (*pl != NULL && (*pl)->imm.distanza < imm.distanza)
    {
        pl = &(*pl)->next;
    }

    if (*pl != NULL && (*pl)->imm.distanza > imm.distanza)
    {
        instesta(pl, imm);
    }

    if (*pl == NULL)
    {
        Immobile i;
        strcpy(i.indirizzo, imm.indirizzo);
        i.vani = imm.vani;
        i.distanza = imm.distanza;
        instesta(pl, i);
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
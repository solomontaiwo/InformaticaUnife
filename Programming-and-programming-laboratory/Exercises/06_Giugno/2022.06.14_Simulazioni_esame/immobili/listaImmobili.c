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
    strcpy(testa->imm.indirizzo, imm.indirizzo);
    testa->imm.vani = imm.vani;
    testa->imm.distanzaCentro = imm.distanzaCentro;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Immobile imm)
{
    while (*pl != NULL && (*pl)->imm.distanzaCentro < imm.distanzaCentro)
        pl = &(*pl)->next;

    if (*pl != NULL && (*pl)->imm.distanzaCentro > imm.distanzaCentro)
    {
        Immobile nuovo;
        strcpy(nuovo.indirizzo, imm.indirizzo);
        nuovo.vani = imm.vani;
        nuovo.distanzaCentro = imm.distanzaCentro;
        insTesta(pl, nuovo);
    }

    if (*pl == NULL)
    {
        Immobile nuovo;
        strcpy(nuovo.indirizzo, imm.indirizzo);
        nuovo.vani = imm.vani;
        nuovo.distanzaCentro = imm.distanzaCentro;
        insTesta(pl, nuovo);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s %d %.3f\n", l->imm.indirizzo, l->imm.vani, l->imm.distanzaCentro);
        l = l->next;
    }
}
#include <stdio.h>
#include <stdlib.h>

#include "listaImmobili.h"

void inizializzaLista(Lista *pl)
{
    *pl = NULL;
}

int vuota(Lista l)
{
    return l == NULL;
}

void insTesta(Lista *pl, Immobile imm)
{
    Nodo *nuovaTesta = (Nodo *)malloc(sizeof(Nodo));
    nuovaTesta->dato = imm;
    nuovaTesta->next = *pl;
    *pl = nuovaTesta;
}

void insOrd(Lista *pl, Immobile imm)
{
    while (*pl && (*pl)->dato.distanzaCentro < imm.distanzaCentro)
        pl = &(*pl)->next;

    insTesta(pl, imm);
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s %d %.2f\n", l->dato.indirizzo, l->dato.vani, l->dato.distanzaCentro);
        l = l->next;
    }
  
}
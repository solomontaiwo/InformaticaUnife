#include <stdio.h>
#include <stdlib.h>

#include "listaGiornate.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

int stessaGiornata(int giorno1, int giorno2, int mese1, int mese2)
{
    if (giorno1 == giorno2 && mese1 == mese2)
    {
        return 1;
    }
    else
        return 0;
}

void insTesta(Lista *pl, Giornata g)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    testa->g = g;
    testa->next = *pl;
    *pl = testa;
}

void aggiornaLista(Lista *pl, Registrazione r)
{
    while (*pl != NULL && (stessaGiornata((*pl)->g.giorno, r.giorno, (*pl)->g.mese, r.mese)) == 0)
        pl = &(*pl)->next;

    if (*pl && (stessaGiornata((*pl)->g.giorno, r.giorno, (*pl)->g.mese, r.mese)) == 1)
        (*pl)->g.ore += r.ore;
    else
    {
        Giornata gNew;
        gNew.giorno = r.giorno;
        gNew.mese = r.mese;
        gNew.ore = r.ore;
        insTesta(pl, gNew);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d/%d %.1f\n", l->g.giorno, l->g.mese, l->g.ore);
        l = l->next;
    }
}
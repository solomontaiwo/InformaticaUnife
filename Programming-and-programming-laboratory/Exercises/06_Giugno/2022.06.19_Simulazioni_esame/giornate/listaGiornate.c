#include <stdio.h>
#include <stdlib.h>

#include "listaGiornate.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Giornata g)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    testa->g.giorno = g.giorno;
    testa->g.mese = g.mese;
    testa->g.oreLavorate = g.oreLavorate;
    testa->next = *pl;
    *pl = testa;
}

int stessoGiorno(int giorno1, int giorno2, int mese1, int mese2)
{
    if (giorno1 == giorno2)
        if (mese1 == mese2)
            return 1;
        else
            return 0;
}

void aggiorna(Lista *pl, Record r)
{
    while (*pl != NULL && stessoGiorno((*pl)->g.giorno, r.giorno, (*pl)->g.mese, r.mese) != 1)
        pl = &(*pl)->next;

    if (*pl && stessoGiorno((*pl)->g.giorno, r.giorno, (*pl)->g.mese, r.mese) == 1)
    {
        (*pl)->g.oreLavorate += r.ore;
    }

    if (*pl == NULL)
    {
        Giornata nuova;
        nuova.giorno = r.giorno;
        nuova.mese = r.mese;
        nuova.oreLavorate = r.ore;
        insTesta(pl, nuova);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d/%d %.1f\n", l->g.giorno, l->g.mese, l->g.oreLavorate);
        l = l->next;
    }
}
#include <stdio.h>
#include <stdlib.h>

#include "listaGiornate.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d/%d %.1f\n", l->g.giorno, l->g.mese, l->g.oreTotaliImpiegate);
        l = l->next;
    }
}

int confrontoDate(int g1, int m1, int g2, int m2)
{
    if (m1 != m2)
        return m1 - m2;
    return g1 - g2;
}

void insTesta(Lista *pl, Giornata g)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    testa->g = g;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Record r)
{
    while (*pl != NULL && confrontoDate((*pl)->g.giorno, (*pl)->g.mese, r.giorno, r.mese) != 0)
        pl = &(*pl)->next;

    if (*pl && confrontoDate((*pl)->g.giorno, (*pl)->g.mese, r.giorno, r.mese) == 0)
    {
        (*pl)->g.oreTotaliImpiegate += r.oreImpiegate;
    }
    else
    {
        Giornata n;
        n.giorno = r.giorno;
        n.mese = r.mese;
        n.oreTotaliImpiegate = r.oreImpiegate;
        insTesta(pl, n);
    }
}
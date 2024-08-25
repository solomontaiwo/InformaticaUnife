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
    testa->g = g;
    testa->next = *pl;
    *pl = testa;
}

int giornoUguale(int giorno1, int giorno2, int mese1, int mese2)
{
    if (giorno1 == giorno2)
    {
        if (mese1 == mese2)
            return 1;
    }
    return 0;
}

void aggiorna(Lista *pl, Registrazione r)
{
    while (*pl != NULL && (giornoUguale((*pl)->g.giorno, r.giorno, (*pl)->g.mese, r.mese) != 1))
        pl = &(*pl)->next;

    if (*pl != NULL && (giornoUguale((*pl)->g.giorno, r.giorno, (*pl)->g.mese, r.mese) == 1))
    {
        (*pl)->g.ore += r.ore;
    }

    if (*pl == NULL)
    {
        Giornata g;
        g.giorno = r.giorno;
        g.mese = r.mese;
        g.ore = r.ore;
        insTesta(pl, g);
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
#include <stdio.h>
#include <stdlib.h>

#include "listaEsami.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

Esito esito(int pratico, int teorico)
{
    Esito e;
    e.superato = pratico >= 12 && teorico >= 6;
    e.somma = pratico + teorico;
    return e;
}

void stampa(Lista l)
{
    while (l)
    {
        Esito e = esito(l->d.punteggioPratica, l->d.punteggioTeorica);
        printf("%d ", l->d.matricola);

        if (e.superato)
        {
            if (e.somma > 30)
                printf("30 e lode\n");
            else
                printf("%d\n", e.somma);
        }
        else
            printf("non superato\n");
        l = l->next;
    }
}

void insTesta(Lista *pl, Dato d)
{
    Nodo *nuovaTesta = (Nodo *)malloc(sizeof(Nodo));
    nuovaTesta->d = d;
    nuovaTesta->next = *pl;
    *pl = nuovaTesta;
}

void aggiorna(Lista *pl, Risultato r)
{

    while ((*pl) != NULL && (*pl)->d.matricola != r.matricola)
    {
        pl = &(*pl)->next;
    }

    if (*pl == NULL)
    {
        Dato d;
        d.matricola = r.matricola;
        d.punteggioPratica = -1;
        d.punteggioTeorica = -1;
        insTesta(pl, d);
    }
}
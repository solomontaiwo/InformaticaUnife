#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaPazienti.h"

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
    while (*pl != NULL && strcmp((*pl)->d.cf, r.cf) != 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->d.cf, r.cf) == 0)
    {
        (*pl)->d.saturazione += r.saturazione;
        (*pl)->d.temperatura += r.temperatura;
        (*pl)->d.numeroRilevazioni++;
    }

    if (*pl == NULL)
    {
        Dato d;
        strcpy(d.cf, r.cf);
        d.numeroRilevazioni = 1;
        d.saturazione = r.saturazione;
        d.temperatura = r.temperatura;
        insTesta(pl, d);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s %.2f %.2f\n", l->d.cf, l->d.temperatura / l->d.numeroRilevazioni, l->d.saturazione / l->d.numeroRilevazioni);
        l = l->next;
    }
}

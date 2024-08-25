#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaPazienti.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Paziente p)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    testa->p = p;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Rilevazione r)
{
    while (*pl != NULL && strcmp((*pl)->p.cf, r.cf) != 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->p.cf, r.cf) == 0)
    {
        (*pl)->p.numeroRilevazioni++;
        (*pl)->p.saturazione += r.saturazione;
        (*pl)->p.temperatura += r.temperatura;
    }

    if (*pl == NULL)
    {
        Paziente p;
        strcpy(p.cf, r.cf);
        p.numeroRilevazioni = 1;
        p.saturazione = r.saturazione;
        p.temperatura = r.temperatura;
        insTesta(pl, p);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s %.1f %.1f\n", l->p.cf, l->p.temperatura / l->p.numeroRilevazioni, l->p.saturazione / l->p.numeroRilevazioni);
        l = l->next;
    }
}
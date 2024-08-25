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
    strcpy(testa->p.cf, p.cf);
    testa->p.saturazione = p.saturazione;
    testa->p.temperatura = p.temperatura;
    testa->p.numeroRilevazioni = p.numeroRilevazioni;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Rilevazione r)
{
    while (*pl != NULL && strcmp((*pl)->p.cf, r.cf) < 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->p.cf, r.cf) > 0)
    {
        Paziente degente;
        strcpy(degente.cf, r.cf);
        degente.saturazione = r.saturazione;
        degente.temperatura = r.temperatura;
        degente.numeroRilevazioni = 1;
        insTesta(pl, degente);
    }

    if (*pl != NULL && strcmp((*pl)->p.cf, r.cf) == 0)
    {
        (*pl)->p.saturazione += r.saturazione;
        (*pl)->p.temperatura += r.temperatura;
        (*pl)->p.numeroRilevazioni++;
    }

    if (*pl == NULL)
    {
        Paziente degente;
        strcpy(degente.cf, r.cf);
        degente.saturazione = r.saturazione;
        degente.temperatura = r.temperatura;
        degente.numeroRilevazioni = 1;
        insTesta(pl, degente);
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
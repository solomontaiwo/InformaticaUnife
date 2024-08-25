#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaPazienti.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Paziente paz)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    strcpy(testa->paz.cf, paz.cf);
    testa->paz.numeroRilevazioni = paz.numeroRilevazioni;
    testa->paz.temperatura = paz.temperatura;
    testa->paz.saturazione = paz.saturazione;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Rilevazione ril)
{
    while (*pl != NULL && strcmp((*pl)->paz.cf, ril.cf) != 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->paz.cf, ril.cf) == 0)
    {
        (*pl)->paz.numeroRilevazioni++;
        (*pl)->paz.saturazione += ril.saturazione;
        (*pl)->paz.temperatura += ril.temperatura;
    }

    if (*pl == NULL)
    {
        Paziente paz;
        strcpy(paz.cf, ril.cf);
        paz.numeroRilevazioni = 1;
        paz.saturazione = ril.saturazione;
        paz.temperatura = ril.temperatura;
        insTesta(pl, paz);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s ", l->paz.cf);
        printf("%.1f %.1f\n", l->paz.temperatura / l->paz.numeroRilevazioni, l->paz.saturazione / l->paz.numeroRilevazioni);
        l = l->next;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaNazioni.h"

void nuovaLista(Lista *pl)
{
    pl = NULL;
}

void insTesta(Lista *pl, Dato n)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    strcpy(testa->n.nazione, n.nazione);
    testa->n.ori = n.ori;
    testa->n.argenti = n.argenti;
    testa->n.bronzi = n.bronzi;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Nazione n, int posizione)
{
    while (*pl != NULL && strcmp((*pl)->n.nazione, n) != 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->n.nazione, n) == 0)
    {
        switch (posizione)
        {
        case 1:
            (*pl)->n.ori++;
            break;
        case 2:
            (*pl)->n.argenti++;
            break;
        case 3:
            (*pl)->n.bronzi++;
            break;
        }
    }

    if (*pl == NULL)
    {
        Dato d;
        strcpy(d.nazione, n);
        d.ori = d.argenti = d.bronzi = 0;
        switch (posizione)
        {
        case 1:
            d.ori++;
            break;
        case 2:
            d.argenti++;
            break;
        case 3:
            d.bronzi++;
            break;
        }
        insTesta(pl, d);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s: %d ori, %d argenti, %d bronzi\n", l->n.nazione, l->n.ori, l->n.argenti, l->n.bronzi);
        l = l->next;
    }
}
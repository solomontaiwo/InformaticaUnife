#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaNazioni.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Nazione n)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    strcpy(testa->n.nm, n.nm);
    testa->n.ori = n.ori;
    testa->n.argenti = n.argenti;
    testa->n.bronzi = n.bronzi;
    testa->next = *pl;
    *pl = testa;
}

void aggiornaLista(Lista *pl, nomeNazione nm, int posizione)
{
    while (*pl != NULL && strcmp((*pl)->n.nm, nm) != 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->n.nm, nm) == 0)
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
        Nazione n;
        strcpy(n.nm, nm);
        switch (posizione)
        {
        case 1:
            n.ori = 1;
            n.argenti = 0;
            n.bronzi = 0;
            break;
        case 2:
            n.ori = 0;
            n.argenti = 1;
            n.bronzi = 0;
            break;
        case 3:
            n.ori = 0;
            n.argenti = 0;
            n.bronzi = 1;
            break;
        }
        insTesta(pl, n);
    }
}

void stampaLista(Lista l)
{
    while (l)
    {
        printf("%s: %d ori, %d argenti, %d bronzi\n", l->n.nm, l->n.ori, l->n.argenti, l->n.bronzi);
        l = l->next;
    }
}
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
    testa->n = n;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Posizioni p, int medaglia)
{
    while (*pl != NULL && strcmp((*pl)->n.nomeNazione, p) != 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->n.nomeNazione, p) == 0)
    {
        switch (medaglia)
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
        strcpy(n.nomeNazione, p);
        switch (medaglia)
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

void stampa(Lista l)
{
    while (l)
    {
        printf("%s: %d ori, %d argenti, %d bronzi\n", l->n.nomeNazione, l->n.ori, l->n.argenti, l->n.bronzi);
        l = l->next;
    }
}
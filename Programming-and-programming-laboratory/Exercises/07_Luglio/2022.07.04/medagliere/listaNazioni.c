#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaNazioni.h"

void nuovaLista(Lista *pl)
{
    pl = 0;
}

void insTesta(Lista *pl, Dato d)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    strcpy(testa->d.n, d.n);
    testa->d.ori = d.ori;
    testa->d.bronzi = d.bronzi;
    testa->d.argenti = d.argenti;
    testa->next = *pl;
    *pl = testa;
}

void aggiornaLista(Lista *pl, Nazione n, int posizione)
{
    while (*pl != NULL && strcmp((*pl)->d.n, n) != 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->d.n, n) == 0)
    {
        switch (posizione)
        {
        case 1:
            (*pl)->d.ori++;
            break;
        case 2:
            (*pl)->d.argenti++;
            break;
        case 3:
            (*pl)->d.bronzi++;
            break;
        }
    }

    if (*pl == NULL)
    {
        Dato d;
        strcpy(d.n, n);
        switch (posizione)
        {
        case 1:
            d.ori = 1;
            d.argenti = d.bronzi = 0;
            break;
        case 2:
            d.argenti = 1;
            d.ori = d.bronzi = 0;
            break;
        case 3:
            d.bronzi = 1;
            d.ori = d.argenti = 0;
            break;
        }
        insTesta(pl, d);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s: %d ori, %d argenti, %d bronzi\n", l->d.n, l->d.ori, l->d.argenti, l->d.bronzi);
        l = l->next;
    }
}
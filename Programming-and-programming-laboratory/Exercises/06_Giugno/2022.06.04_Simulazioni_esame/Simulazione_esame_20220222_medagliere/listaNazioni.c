#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaNazioni.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Dato d)
{
    Nodo *nTesta = (Nodo *)malloc(sizeof(Nodo));
    nTesta->d = d;
    nTesta->next = *pl;
    *pl = nTesta;
}

void aggiorna(Lista *pl, char *r, int numeroCiclo)
{
    while (*pl != NULL && (strcmp((*pl)->d.nomeNazione, r)) != 0)
        pl = &(*pl)->next;

    if (*pl != NULL && (strcmp((*pl)->d.nomeNazione, r)) == 0)
    {
        if (numeroCiclo == 1)
            (*pl)->d.ori++;
        if (numeroCiclo == 2)
            (*pl)->d.argenti++;
        if (numeroCiclo == 3)
            (*pl)->d.bronzi++;
    }

    if (*pl == NULL)
    {
        Dato d;
        strcpy(d.nomeNazione, r);
        if (numeroCiclo == 1)
        {
            d.ori = 1;
            d.argenti = 0;
            d.bronzi = 0;
        }
        if (numeroCiclo == 2)
        {
            d.ori = 0;
            d.argenti = 1;
            d.bronzi = 0;
        }
        if (numeroCiclo == 3)
        {
            d.ori = 0;
            d.argenti = 0;
            d.bronzi = 1;
        }
        insTesta(pl, d);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s: ", l->d.nomeNazione);
        printf("%d ori, ", l->d.ori);
        printf("%d argenti, ", l->d.argenti);
        printf("%d bronzi\n", l->d.bronzi);
        l = l->next;
    }
}
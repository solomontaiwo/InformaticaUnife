#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaPersone.h"

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
    while (*pl != NULL && (strcmp((*pl)->d.cf, r.cf) < 0))
    {
        pl = &(*pl)->next;
    }

    if (*pl != NULL && (strcmp((*pl)->d.cf, r.cf) == 0))
    {
        if (r.evento == 'T')
            (*pl)->d.tampone = 1;
        if (r.evento == 'V')
            (*pl)->d.vaccino = 1;
    }

    if (*pl == NULL || (strcmp((*pl)->d.cf, r.cf) != 0))
    {
        Dato d;
        strcpy(d.cf, r.cf);

        if (r.evento == 'T')
        {
            d.tampone = 1;
            d.vaccino = 0;
        }
        else
        {
            d.vaccino = 1;
            d.tampone = 0;
        }

        insTesta(pl, d);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s, ", l->d.cf);
        if (l->d.tampone && l->d.vaccino)
            printf("tampone, vaccino");
        else if (l->d.tampone)
            printf("tampone");
        else if (l->d.vaccino)
            printf("vaccino");
        printf("\n");
        l = l->next;
    }
}
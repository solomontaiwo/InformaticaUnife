#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaPersone.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
};

void insTesta(Lista *pl, Paziente p)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    testa->p = p;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Record r)
{
    while (*pl != NULL && strcmp((*pl)->p.cf, r.cf) < 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->p.cf, r.cf) > 0)
    {
        Paziente p;
        strcpy(p.cf, r.cf);
        if (r.evento == 'T')
        {
            p.tampone = 1;
            p.vaccino = 0;
        }
        else
        {
            p.tampone = 0;
            p.vaccino = 1;
        }
        insTesta(pl, p);
    }

    if (*pl != NULL && strcmp((*pl)->p.cf, r.cf) == 0)
    {
        if (r.evento == 'T')
            (*pl)->p.tampone = 1;
        else
            (*pl)->p.vaccino = 1;
    }

    if (*pl == NULL)
    {
        Paziente p;
        strcpy(p.cf, r.cf);
        if (r.evento == 'T')
        {
            p.tampone = 1;
            p.vaccino = 0;
        }
        else
        {
            p.tampone = 0;
            p.vaccino = 1;
        }
        insTesta(pl, p);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s", l->p.cf);
        if (l->p.tampone)
            printf(", tampone");
        if (l->p.vaccino)
            printf(", vaccino");
        puts("");
        l = l->next;
    }
}
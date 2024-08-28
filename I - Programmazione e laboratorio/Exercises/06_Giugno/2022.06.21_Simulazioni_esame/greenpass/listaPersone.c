#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaPersone.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Persona p)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    strcpy(testa->p.cf, p.cf);
    testa->p.tampone = p.tampone;
    testa->p.vaccino = p.vaccino;
    testa->next = *pl;
    *pl = testa;
}

void aggiornaLista(Lista *pl, Record r)
{
    while (*pl != NULL && strcmp((*pl)->p.cf, r.cf) < 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->p.cf, r.cf) > 0)
    {
        Persona pNew;
        strcpy(pNew.cf, r.cf);
        switch (r.evento)
        {
        case 'T':
            pNew.tampone = 1;
            pNew.vaccino = 0;
            break;
        case 'V':
            pNew.vaccino = 1;
            pNew.tampone = 0;
            break;
        }
        insTesta(pl, pNew);
    }

    if (*pl != NULL && strcmp((*pl)->p.cf, r.cf) == 0)
        switch (r.evento)
        {
        case 'T':
            (*pl)->p.tampone = 1;
            break;
        case 'V':
            (*pl)->p.vaccino = 1;
            break;
        }

    if (*pl == NULL)
    {
        Persona pNew;
        strcpy(pNew.cf, r.cf);
        switch (r.evento)
        {
        case 'T':
            pNew.tampone = 1;
            pNew.vaccino = 0;
            break;
        case 'V':
            pNew.tampone = 0;
            pNew.vaccino = 1;
        }
        insTesta(pl, pNew);
    }
}

void stampaLista(Lista l)
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaPersone.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Persona per)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    strcpy(testa->per.cf, per.cf);
    testa->per.tampone = per.tampone;
    testa->per.vaccino = per.vaccino;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Registrazione reg)
{
    while (*pl != NULL && strcmp((*pl)->per.cf, reg.cf) < 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->per.cf, reg.cf) > 0)
    {
        Persona per;
        strcpy(per.cf, reg.cf);
        switch (reg.evento)
        {
        case 'T':
            per.tampone = 1;
            per.vaccino = 0;
            break;
        case 'V':
            per.vaccino = 1;
            per.tampone = 0;
            break;
        }
        insTesta(pl, per);
    }

    if (*pl != NULL && strcmp((*pl)->per.cf, reg.cf) == 0)
    {
        switch (reg.evento)
        {
        case 'T':
            (*pl)->per.tampone = 1;
            break;
        case 'V':
            (*pl)->per.vaccino = 1;
            break;
        }
    }

    if (*pl == NULL)
    {
        Persona per;
        strcpy(per.cf, reg.cf);
        switch (reg.evento)
        {
        case 'T':
            per.tampone = 1;
            per.vaccino = 0;
            break;
        case 'V':
            per.vaccino = 1;
            per.tampone = 0;
            break;
        }
        insTesta(pl, per);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s", l->per.cf);
        if (l->per.tampone)
            printf(", tampone");
        if (l->per.vaccino)
            printf(", vaccino");
        puts("");
        l = l->next;
    }
}
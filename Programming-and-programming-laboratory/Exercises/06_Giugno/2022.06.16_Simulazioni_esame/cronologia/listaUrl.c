#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "listaUrl.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Sito s)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    strcpy(testa->s.url, s.url);
    testa->s.numeroVisite = s.numeroVisite;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Visita v)
{
    while (*pl != NULL && strcmp((*pl)->s.url, v.url) != 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->s.url, v.url) == 0)
    {
        (*pl)->s.numeroVisite++;
    }

    if (*pl == NULL)
    {
        Sito nuovoSito;
        strcpy(nuovoSito.url, v.url);
        nuovoSito.numeroVisite = 1;
        insTesta(pl, nuovoSito);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        if (l->s.numeroVisite >= 5)
            printf("%s %d\n", l->s.url, l->s.numeroVisite);
        l = l->next;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUtenti.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Nodo n)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    strcpy(testa->r.numero, n.r.numero);
    testa->r.piano = n.r.piano;
    testa->r.credito = n.r.credito;
    testa->next = *pl;
    *pl = testa;
}

void creaLista(Lista *pl, Record r)
{
    while (*pl != NULL && strcmp((*pl)->r.numero, r.numero) < 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->r.numero, r.numero) > 0)
    {
        Nodo n;
        strcpy(n.r.numero, r.numero);
        n.r.piano = r.piano;
        n.r.credito = r.credito;
        insTesta(pl, n);
    }

    if (*pl == NULL)
    {
        Nodo n;
        strcpy(n.r.numero, r.numero);
        n.r.piano = r.piano;
        n.r.credito = r.credito;
        insTesta(pl, n);
    }
}

void aggiornaLista(Lista *pl, Chiamata c)
{
    while (*pl != NULL && strcmp((*pl)->r.numero, c.numero) != 0)
        pl = &(*pl)->next;

    if (strcmp((*pl)->r.numero, c.numero) == 0)
    {
        switch ((*pl)->r.piano)
        {
        case 'A':
            (*pl)->r.credito -= (0.15 + (0.08 * ((c.durata / 60) + 1)));
            break;
        case 'B':
            (*pl)->r.credito -= ((0.12 / 60) * c.durata);
            break;
        }
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s %.2f\n", l->r.numero, l->r.credito);
        l = l->next;
    }
}
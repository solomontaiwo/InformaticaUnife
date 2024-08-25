#include <stdio.h>
#include <stdlib.h>

#include "listaCani.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Cane c)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    testa->c = c;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Record r)
{
    while (*pl != NULL && (*pl)->c.chipCane != r.chipCane)
        pl = &(*pl)->next;

    if (*pl != NULL && (*pl)->c.chipCane == r.chipCane)
    {
        switch (r.vaccino)
        {
        case 'C':
            (*pl)->c.cimurro++;
            break;
        case 'E':
            (*pl)->c.epatite++;
            break;
        case 'P':
            (*pl)->c.parvovirosi++;
            break;
        }
    }

    if (*pl == NULL)
    {
        Cane c;
        c.chipCane = r.chipCane;
        switch (r.vaccino)
        {
        case 'C':
            c.cimurro = 1;
            c.epatite = 0;
            c.parvovirosi = 0;
            break;
        case 'E':
            c.cimurro = 0;
            c.epatite = 1;
            c.parvovirosi = 0;
            break;
        case 'P':
            c.cimurro = 0;
            c.epatite = 0;
            c.parvovirosi = 1;
            break;
        }
        insTesta(pl, c);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d: ", l->c.chipCane);
        if (!(l->c.cimurro))
            printf("cimurro ");
        if (!(l->c.epatite))
            printf("epatite ");
        if (!(l->c.parvovirosi))
            printf("parvovirosi ");
        puts("");
        l = l->next;
    }
}
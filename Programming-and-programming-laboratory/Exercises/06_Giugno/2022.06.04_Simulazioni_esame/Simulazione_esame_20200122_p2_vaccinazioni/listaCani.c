#include <stdio.h>
#include <stdlib.h>

#include "listaCani.h"

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
    while (*pl != NULL && (*pl)->d.numeroCane != r.numeroChip)
        pl = &(*pl)->next;

    if (*pl != NULL && (*pl)->d.numeroCane == r.numeroChip)
    {
        if (r.tipoVaccino == 'C')
            (*pl)->d.cimurro = 1;
        if (r.tipoVaccino == 'P')
            (*pl)->d.parvovirosi = 1;
        if (r.tipoVaccino == 'E')
            (*pl)->d.epatite = 1;
    }

    if (*pl == NULL)
    {
        Dato d;
        d.numeroCane = r.numeroChip;

        if (r.tipoVaccino == 'C')
            d.cimurro = 1;
        else
            d.cimurro = 0;

        if (r.tipoVaccino == 'E')
            d.epatite = 1;
        else
            d.epatite = 0;

        if (r.tipoVaccino == 'P')
            d.parvovirosi = 1;
        else
            d.parvovirosi = 0;

        insTesta(pl, d);
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d: ", l->d.numeroCane);
        if (!(l->d.cimurro))
            printf("cimurro ");
        if (!(l->d.epatite))
            printf("epatite ");
        if (!(l->d.parvovirosi))
            printf("parvovirosi ");
        printf("\n");
        l = l->next;
    }
}
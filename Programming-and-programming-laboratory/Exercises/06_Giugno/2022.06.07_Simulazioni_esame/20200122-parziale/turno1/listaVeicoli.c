#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaVeicoli.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Veicolo v)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    strcpy(testa->v.targa, v.targa);
    testa->v.contatore = v.contatore;
    testa->next = *pl;
    *pl = testa;
}

void creaLista(Lista *pl, Accesso a)
{
    while (*pl != NULL && strcmp((*pl)->v.targa, a.targa) != 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->v.targa, a.targa) == 0)
        (*pl)->v.contatore++;

    if (*pl == NULL)
    {
        Veicolo v;
        strcpy(v.targa, a.targa);
        v.contatore = 1;
        insTesta(pl, v);
    }
}

void fattura(float numeroAccessi)
{
    if (numeroAccessi <= 5)
        printf("%.2f\n", numeroAccessi * 2.00);
    else if (numeroAccessi >= 6 && numeroAccessi <= 10)
        printf("%.2f\n", numeroAccessi * 1.90);
    else
        printf("%.2f\n", numeroAccessi * 1.80);
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s ", l->v.targa);
        fattura(l->v.contatore);
        l = l->next;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaVeicoli.h"

void inizializzaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Veicolo v)
{
    Nodo *nuovaTesta = (Nodo *)malloc(sizeof(Nodo));
    nuovaTesta->dato = v;
    nuovaTesta->next = *pl;
    *pl = nuovaTesta;
}

void aggiorna(Lista *pl, char targa[])
{
    while (*pl && strcmp((*pl)->dato.targa, targa) != 0)
        pl = &(*pl)->next;

    if (*pl == NULL)
    {
        Veicolo v;
        strcpy(v.targa, targa);
        v.accessi = 0;
        insTesta(pl, v);
    }
    (*pl)->dato.accessi++;
}

float importo(int accessi)
{
    if (accessi <= 0)
        return 0.0;
    if (accessi <= 5)
        return 2.0 * accessi;
    if (accessi <= 10)
        return 1.9 * accessi;
    return 1.8 * accessi;
}

void stampaImporti(Lista l)
{
    while (l)
    {
        printf("%s %.2f\n", l->dato.targa, importo(l->dato.accessi));
        l = l->next;
    }
}
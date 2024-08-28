#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaNazioni.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Nazione naz)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    strcpy(testa->n.nazione, naz.nazione);
    testa->n.ori = naz.ori;
    testa->n.argenti = naz.argenti;
    testa->n.bronzi = naz.bronzi;
    testa->next = *pl;
    *pl = testa;
}

void aggiornaLista(Lista *pl, nomeNazione naz, int posizione)
{
    while (*pl != NULL && strcmp((*pl)->n.nazione, naz) != 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->n.nazione, naz) == 0)
    {
        switch (posizione)
        {
        case 1:
            (*pl)->n.ori++;
            break;
        case 2:
            (*pl)->n.argenti++;
            break;
        case 3:
            (*pl)->n.bronzi++;
            break;
        }
    }

    if (*pl == NULL)
    {

        Nazione nuovaNazione;
        strcpy(nuovaNazione.nazione, naz);

        switch (posizione)
        {
        case 1:
            nuovaNazione.ori = 1;
            nuovaNazione.argenti = 0;
            nuovaNazione.bronzi = 0;
            break;
        case 2:
            nuovaNazione.ori = 0;
            nuovaNazione.argenti = 1;
            nuovaNazione.bronzi = 0;
            break;
        case 3:
            nuovaNazione.ori = 0;
            nuovaNazione.argenti = 0;
            nuovaNazione.bronzi = 1;
            break;
        }

        insTesta(pl, nuovaNazione);
    }
}

void stampaLista(Lista l)
{
    while (l)
    {
        printf("%s: %d ori, %d argenti, %d bronzi.\n", l->n.nazione, l->n.ori, l->n.argenti, l->n.bronzi);
        l = l->next;
    }
}
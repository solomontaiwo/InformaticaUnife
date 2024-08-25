#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUtenti.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Utente ut)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    strcpy(testa->ut.cf, ut.cf);
    testa->ut.primaAttivita = ut.primaAttivita;
    testa->ut.secondaAttivita = ut.secondaAttivita;
    testa->ut.terzaAttivita = ut.terzaAttivita;
    testa->next = *pl;
    *pl = testa;
}

void creaLista(Lista *pl, cf c)
{
    while (*pl != NULL)
    {
        pl = &(*pl)->next;
    }

    if (*pl == NULL)
    {
        Utente ut;
        strcpy(ut.cf, c);
        ut.primaAttivita = 4;
        ut.secondaAttivita = 4;
        ut.terzaAttivita = 4;
        insTesta(pl, ut);
    }
}

void aggiorna(Lista *pl, Ingresso in)
{
    while (*pl != NULL && strcmp((*pl)->ut.cf, in.cf) != 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->ut.cf, in.cf) == 0)
    {
        switch (in.attivita)
        {
        case 1:
            (*pl)->ut.primaAttivita--;
            if ((*pl)->ut.primaAttivita < 0)
            {
                printf("Codice Fiscale %s, attivita 1: Accesso negato\n");
                (*pl)->ut.primaAttivita = 0;
            }
            break;
        case 2:
            (*pl)->ut.secondaAttivita--;
            if ((*pl)->ut.secondaAttivita < 0)
            {
                printf("Codice Fiscale %s, attivita 2: Accesso negato\n");
                (*pl)->ut.secondaAttivita = 0;
            }
            break;
        case 3:
            (*pl)->ut.terzaAttivita--;
            if ((*pl)->ut.terzaAttivita < 0)
            {
                printf("Codice Fiscale %s, attivita 3: Accesso negato\n");
                (*pl)->ut.terzaAttivita = 0;
            }
            break;
        }
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s: %d %d %d\n", l->ut.cf, l->ut.primaAttivita, l->ut.secondaAttivita, l->ut.terzaAttivita);
        l = l->next;
    }
}
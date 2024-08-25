#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUtenti.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Utente u)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    strcpy(testa->ut.cf, u.cf);
    testa->ut.primaAttivita = u.primaAttivita;
    testa->ut.secondaAttivita = u.secondaAttivita;
    testa->ut.terzaAttivita = u.terzaAttivita;
    testa->next = *pl;
    *pl = testa;
}

void creaLista(Lista *pl, cf codiceFiscale)
{
    while (*pl != NULL)
        pl = &(*pl)->next;

    if (*pl == NULL)
    {
        Utente nuovo;
        strcpy(nuovo.cf, codiceFiscale);
        nuovo.primaAttivita = nuovo.secondaAttivita = nuovo.terzaAttivita = 4;
        insTesta(pl, nuovo);
    }
}

void aggiornaLista(Lista *pl, Ingresso in)
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
                printf("Codice Fiscale %s, attivita' 1: Accesso negato\n", (*pl)->ut.cf);
                (*pl)->ut.primaAttivita = 0;
            }
            break;
        case 2:
            (*pl)->ut.secondaAttivita--;
            if ((*pl)->ut.secondaAttivita < 0)
            {
                printf("Codice Fiscale %s, attivita' 2: Accesso negato\n", (*pl)->ut.cf);
                (*pl)->ut.secondaAttivita = 0;
            }
            break;
        case 3:
            (*pl)->ut.terzaAttivita--;
            if ((*pl)->ut.terzaAttivita < 0)
            {
                printf("Codice Fiscale %s, attivita' 3: Accesso negato\n", (*pl)->ut.cf);
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
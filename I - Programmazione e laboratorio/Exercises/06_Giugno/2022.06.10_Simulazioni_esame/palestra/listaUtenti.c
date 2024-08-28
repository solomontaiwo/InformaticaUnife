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
    testa->u = u;
    testa->next = *pl;
    *pl = testa;
}

void creaLista(Lista *pl, Iscritto i)
{
    while (*pl != NULL)
        pl = &(*pl)->next;

    if (*pl == NULL)
    {
        Utente u;
        strcpy(u.cf, i.cf);
        u.primaAttivita = u.secondaAttivita = u.terzaAttivita = 4;
        insTesta(pl, u);
    }
}

void aggiornaLista(Lista *pl, Ingresso i)
{
    while (*pl != NULL && strcmp((*pl)->u.cf, i.cf) != 0)
        pl = &(*pl)->next;

    if (*pl != NULL && strcmp((*pl)->u.cf, i.cf) == 0)
    {
        switch (i.attivita)
        {
        case 1:
            (*pl)->u.primaAttivita--;
            if ((*pl)->u.primaAttivita < 0)
            {
                printf("Codice Fiscale %s, attivita' 1: Accesso negato\n");
                (*pl)->u.primaAttivita = 0;
            }
           
            break;
        case 2:
            (*pl)->u.secondaAttivita--;
            if ((*pl)->u.secondaAttivita < 0)
            {
                printf("Codice Fiscale %s, attivita' 2: Accesso negato\n");
                (*pl)->u.secondaAttivita = 0;
            }
            
            break;
        case 3:
            (*pl)->u.terzaAttivita--;
            if ((*pl)->u.terzaAttivita < 0)
            {
                printf("Codice Fiscale %s, attivita' 3: Accesso negato\n");
                (*pl)->u.terzaAttivita = 0;
            }
           
            break;
        }
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s: %d %d %d\n", l->u.cf, l->u.primaAttivita, l->u.secondaAttivita, l->u.terzaAttivita);
        l = l->next;
    }
}
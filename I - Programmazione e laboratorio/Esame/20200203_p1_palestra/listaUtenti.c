#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUtenti.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Nodo d)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    strcpy(testa->codiceFiscale, d.codiceFiscale);
    testa->primaAttivita = d.primaAttivita;
    testa->secondaAttivita = d.secondaAttivita;
    testa->terzaAttivita = d.terzaAttivita;
    testa->next = *pl;
    *pl = testa;
}

void creaLista(Lista *pl, Utente e)
{
    while (*pl != NULL && strcmp((*pl)->codiceFiscale, e.codiceFiscale) != 0)
        pl = &(*pl)->next;

    if (*pl == NULL)
    {
        Nodo n;
        strcpy(n.codiceFiscale, e.codiceFiscale);
        n.primaAttivita = 4;
        n.secondaAttivita = 4;
        n.terzaAttivita = 4;
        insTesta(pl, n);
    }
}

void aggiorna(Lista *pl, Entrata e)
{
    while (*pl != NULL && strcmp((*pl)->codiceFiscale, e.codiceFiscale) != 0)
        pl = &(*pl)->next;

    if (strcmp((*pl)->codiceFiscale, e.codiceFiscale) == 0)
    {
        switch (e.attivita)
        {
        case 1:
            (*pl)->primaAttivita--;
            if ((*pl)->primaAttivita < 0)
            {
                printf("Codice Fiscale: %s, attivita' 1: accesso negato\n", (*pl)->codiceFiscale);
                (*pl)->primaAttivita = 0;
            }
            break;
        case 2:
            (*pl)->secondaAttivita--;
            if ((*pl)->secondaAttivita < 0)
            {
                printf("Codice Fiscale: %s, attivita' 2: accesso negato\n", (*pl)->codiceFiscale);
                (*pl)->secondaAttivita = 0;
            }
            break;
        case 3:
            (*pl)->terzaAttivita--;
            if ((*pl)->terzaAttivita < 0)
            {
                printf("Codice Fiscale: %s, attivita' 3: accesso negato\n", (*pl)->codiceFiscale);
                (*pl)->terzaAttivita = 0;
            }
            break;
        }
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s: %d %d %d\n", l->codiceFiscale, l->primaAttivita, l->secondaAttivita, l->terzaAttivita);
        l = l->next;
    }
}
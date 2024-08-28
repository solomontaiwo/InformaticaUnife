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
    strcpy(testa->muscoli.cf, u.cf);
    testa->muscoli.attUno = u.attUno;
    testa->muscoli.attDue = u.attDue;
    testa->muscoli.attTre = u.attTre;
    testa->next = *pl;
    *pl = testa;
}

void creaLista(Lista *pl, Iscritto r)
{
    while (*pl != NULL)
        pl = &(*pl)->next;

    if (*pl == NULL)
    {
        Utente muscoli;
        strcpy(muscoli.cf, r.cf);
        muscoli.attUno = 4;
        muscoli.attDue = 4;
        muscoli.attTre = 4;
        insTesta(pl, muscoli);
    }
}

void aggiornaLista(Lista *pl, Ingresso i)
{
    while (*pl != NULL && strcmp((*pl)->muscoli.cf, i.cf) != 0)
        pl = &(*pl)->next;

    while (*pl != NULL && strcmp((*pl)->muscoli.cf, i.cf) == 0)
    {
        switch (i.attivita)
        {
        case 1:
            (*pl)->muscoli.attUno--;
            if ((*pl)->muscoli.attUno < 0)
            {
                printf("Codice Fiscale %s, attivita' 1: accesso negato\n", (*pl)->muscoli.cf);
                (*pl)->muscoli.attUno = 0;
            }
            pl = &(*pl)->next;
            break;
        case 2:
            (*pl)->muscoli.attDue--;
            if ((*pl)->muscoli.attDue < 0)
            {
                printf("Codice Fiscale %s, attivita' 2: accesso negato\n", (*pl)->muscoli.cf);
                (*pl)->muscoli.attDue = 0;
            }
            pl = &(*pl)->next;
            break;
        case 3:
            (*pl)->muscoli.attTre--;
            if ((*pl)->muscoli.attTre < 0)
            {
                printf("Codice Fiscale %s, attivita' 3: accesso negato\n", (*pl)->muscoli.cf);
                (*pl)->muscoli.attTre = 0;
            }
            pl = &(*pl)->next;
            break;
        }
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s: %d %d %d\n", l->muscoli.cf, l->muscoli.attUno, l->muscoli.attDue, l->muscoli.attTre);
        l = l->next;
    }
}
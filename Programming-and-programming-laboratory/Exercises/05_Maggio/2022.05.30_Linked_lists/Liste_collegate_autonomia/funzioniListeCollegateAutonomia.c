#include <stdio.h>
#include <stdlib.h>

#include "funzioniListeCollegateAutonomia.h"

// crea lista vuota
void creaLista(Lista *pl)
{
    *pl = NULL;
}

// restituisce NULL se la lista non contiene elementi
int vuota(Lista l)
{
    return l == NULL;
}

// restituisce 0 perche' una lista non puo' mai essere piena
int piena(Lista l)
{
    return 0;
}

// crea un nuovo nodo che fara' da testa
void insTesta(Lista *pl, int numero)
{
    Nodo *nuovaTesta = (Nodo *)malloc(sizeof(Nodo));
    nuovaTesta->d = numero;
    nuovaTesta->next = *pl;
    *pl = nuovaTesta;
}

// inserimento ordinato facendo una ricerca degli elementi maggiori rispetto a quello da inserire
void insOrd(Lista *pl, int numero)
{
    pl = ricercaOrd(pl, numero);

    insTesta(pl, numero);
}

// ricerca un elemento
Lista *ricerca(Lista *pl, int numero)
{
    while (*pl)
    {
        if ((*pl)->d == numero)
        {
            break;
        }
        pl = &(*pl)->next;
    }
    return pl;
}

// ricerca elemento per inserimento ordinato
Lista *ricercaOrd(Lista *pl, int numero)
{
    while (*pl)
    {

        if ((*pl)->d > numero)
        {
            break;
        }
        pl = &(*pl)->next;
    }
    return pl;
}

// elimina la testa della lista collegata
void elimTesta(Lista *pl)
{
    Nodo *nuovaTesta = (Nodo *)malloc(sizeof(Nodo));
    *pl = (*pl)->next;
    free(nuovaTesta);
}

// elimina un elemento della lista collegata
int elim1(Lista *pl, int numero)
{
    pl = ricerca(pl, numero);
    if (*pl)
    {
        elimTesta(pl);
        return 1;
    }
    return 0;
}

// elimina tutti gli elementi della lista collegat
void elimTutti(Lista *pl, int numero)
{
    pl = ricerca(pl, numero);
    if (*pl)
    {
        elimTesta(pl);
    }
}

// stampa tutti gli elementi della lista
void stampa(Lista l)
{
    while (l)
    {
        printf("%d ", l->d);
        l = l->next;
    }
    puts("");
}
#include <stdio.h>
#include <stdlib.h>

#include "listaEsami.h"

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
    while (*pl != NULL && (*pl)->d.matricola != r.matricola)
        pl = &(*pl)->next;

    if (*pl != NULL && (*pl)->d.matricola == r.matricola && r.prova == 'T')
    {
        (*pl)->d.pun.teorica = r.punteggio;
    }

    if (*pl != NULL && (*pl)->d.matricola == r.matricola && r.prova == 'P')
    {
        (*pl)->d.pun.pratica = r.punteggio;
    }

    if (*pl == NULL)
    {
        Dato d;
        d.matricola = r.matricola;
        if (r.prova == 'T')
            d.pun.teorica = r.punteggio;
        if (r.prova == 'P')
            d.pun.pratica = r.punteggio;
        insTesta(pl, d);
    }
}

void risultato(int teoria, int pratica)
{
    if (teoria + pratica > 30)
        printf("30 e lode\n");
    else if (teoria >= 6 && pratica >= 12)
        printf("%d\n", teoria + pratica);
    else
        printf("non superato\n");
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d ", l->d.matricola);
        risultato(l->d.pun.teorica, l->d.pun.pratica);
        l = l->next;
    }
}
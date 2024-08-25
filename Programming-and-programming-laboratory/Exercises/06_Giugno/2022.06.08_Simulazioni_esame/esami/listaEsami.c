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

void aggiorna(Lista *pl, Studente s)
{
    while (*pl != NULL && (*pl)->d.matricola != s.matricola)
        pl = &(*pl)->next;

    if (*pl != NULL && (*pl)->d.matricola == s.matricola)
    {
        if (s.prova == 'T')
            (*pl)->d.teorica = s.punteggio;
        else
            (*pl)->d.pratica = s.punteggio;
    }

    if (*pl == NULL)
    {
        Dato nuovo;
        nuovo.matricola = s.matricola;
        if (s.prova == 'T')
            nuovo.teorica = s.punteggio;
        else
            nuovo.pratica = s.punteggio;
        insTesta(pl, nuovo);
    }
}

void voto(int punteggioPratica, int punteggioTeorica)
{
    if (punteggioPratica + punteggioTeorica > 30)
        printf("30 e lode\n");
    else if (punteggioPratica >= 12 && punteggioTeorica >= 6)
        printf("%d\n", punteggioPratica + punteggioTeorica);
    else
        printf("non superato\n");
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d ", l->d.matricola);
        voto(l->d.pratica, l->d.teorica);
        l = l->next;
    }
}
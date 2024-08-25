#include <stdio.h>
#include <stdlib.h>

#include "listaEsami.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Candidato cand)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    testa->cand = cand;
    testa->next = *pl;
    *pl = testa;
}

void aggiornaLista(Lista *pl, Risultato ris)
{
    while (*pl != NULL && (*pl)->cand.matricola != ris.matricola)
        pl = &(*pl)->next;

    if (*pl != NULL && (*pl)->cand.matricola == ris.matricola)
    {
        switch (ris.prova)
        {
        case 'T':
            (*pl)->cand.teorica = ris.punteggio;
            break;
        case 'P':
            (*pl)->cand.pratica = ris.punteggio;
            break;
        }
    }

    if (*pl == NULL)
    {
        Candidato new;
        new.matricola = ris.matricola;
        switch (ris.prova)
        {
        case 'T':
            new.teorica = ris.punteggio;
            new.pratica = 0;
            break;
        case 'P':
            new.pratica = ris.punteggio;
            new.teorica = 0;
            break;
        }
        insTesta(pl, new);
    }
}

void punteggio(int votoPratica, int votoTeorica)
{
    if (votoPratica + votoTeorica > 30)
        printf("30 e lode\n");
    else if (votoPratica >= 12 && votoTeorica >= 6)
        printf("%d\n", votoPratica + votoTeorica);
    else
        printf("non superato\n");
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d ", l->cand.matricola);
        punteggio(l->cand.pratica, l->cand.teorica);
        l = l->next;
    }
}
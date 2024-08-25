#include <stdio.h>
#include <stdlib.h>

#include "listaEsami.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Candidato c)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    testa->can.matricola = c.matricola;
    testa->can.punteggioPratica = c.punteggioPratica;
    testa->can.punteggioTeorica = c.punteggioTeorica;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Risultato ris)
{
    while (*pl != NULL && (*pl)->can.matricola != ris.matricola)
        pl = &(*pl)->next;

    if (*pl != NULL && (*pl)->can.matricola == ris.matricola)
    {
        switch (ris.prova)
        {
        case 'P':
            (*pl)->can.punteggioPratica = ris.punteggio;
            break;
        case 'T':
            (*pl)->can.punteggioTeorica = ris.punteggio;
            break;
        }
    }

    if (*pl == NULL)
    {
        Candidato can;
        can.matricola = ris.matricola;
        switch (ris.prova)
        {
        case 'P':
            can.punteggioPratica = ris.punteggio;
            can.punteggioTeorica = 0;
            break;
        case 'T':
            can.punteggioTeorica = ris.punteggio;
            can.punteggioPratica = 0;
            break;
        }
        insTesta(pl, can);
    }
}

void risultato(int teoria, int pratica)
{
    if (pratica + teoria > 30)
        printf("30 e lode\n");
    else if (pratica >= 12 && teoria >= 6)
        printf("%d\n", pratica + teoria);
    else
        printf("non superato\n");
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d ", l->can.matricola);
        risultato(l->can.punteggioTeorica, l->can.punteggioPratica);
        l = l->next;
    }
}
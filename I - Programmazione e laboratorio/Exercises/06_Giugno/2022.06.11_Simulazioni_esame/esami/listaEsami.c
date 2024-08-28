#include <stdio.h>
#include <stdlib.h>

#include "listaEsami.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Studente s)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    testa->s = s;
    testa->next = *pl;
    *pl = testa;
}

void aggiorna(Lista *pl, Risultato r)
{
    while (*pl != NULL && (*pl)->s.matricola != r.matricola)
        pl = &(*pl)->next;

    if (*pl != NULL && (*pl)->s.matricola == r.matricola)
    {
        switch (r.tipoProva)
        {
        case 'T':
            (*pl)->s.punteggioTeorica = r.punteggio;
            break;
        case 'P':
            (*pl)->s.punteggioPratica = r.punteggio;
            break;
        }
    }

    if (*pl == NULL)
    {
        Studente stud;
        stud.matricola = r.matricola;
        switch (r.tipoProva)
        {
        case 'T':
            stud.punteggioTeorica = r.punteggio;
            break;
        case 'P':
            stud.punteggioPratica = r.punteggio;
            break;
        }
        insTesta(pl, stud);
    }
}

void voto(int teorica, int pratica)
{
    if (teorica + pratica > 30)
        printf("30 e lode\n");
    else if (teorica >= 6 && pratica >= 12)
        printf("%d\n", teorica + pratica);
    else
        printf("non superato\n");
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d ", l->s.matricola);
        voto(l->s.punteggioTeorica, l->s.punteggioPratica);
        l = l->next;
    }
}
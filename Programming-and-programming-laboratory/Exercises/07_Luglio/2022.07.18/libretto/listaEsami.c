#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "listaEsami.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Record r)
{
    Nodo *testa = (Nodo *)malloc(sizeof(Nodo));
    strcpy(testa->r.nomeInsegnamento, r.nomeInsegnamento);
    testa->r.giorno = r.giorno;
    testa->r.mese = r.mese;
    testa->r.anno = r.anno;
    testa->r.voto = r.voto;
    testa->next = *pl;
    *pl = testa;
}

int diffDate(Data d1, Data d2)
{
    if (d1.anno != d2.anno)
        return d1.anno - d2.anno;
    if (d1.mese != d2.mese)
        return d1.mese - d2.mese;
    return d1.giorno - d2.giorno;
}

void aggiornaLista(Lista *pl, Record r)
{
    while (*pl != NULL && strcmp((*pl)->r.nomeInsegnamento, r.nomeInsegnamento) != 0)
        pl = &(*pl)->next;

    if (*pl == NULL)
        insTesta(pl, r);
    else
    {
        Data d1 = {(*pl)->r.giorno, (*pl)->r.mese, (*pl)->r.anno},
             d2 = {r.giorno, r.mese, r.anno};
        if (diffDate(d1, d2) < 0)
        {
            (*pl)->r.giorno = r.giorno;
            (*pl)->r.mese = r.mese;
            (*pl)->r.anno = r.anno;
            (*pl)->r.voto = r.voto;
        }
    }
}

void stampaLista(Lista l)
{
    int n_esami = 0, somma = 0;

    while (l)
    {
        n_esami++;
        somma += l->r.voto;
        printf("%s %d/%d/%d %d\n", l->r.nomeInsegnamento, l->r.giorno, l->r.mese,
               l->r.anno, l->r.voto);
        l = l->next;
    }
    printf("\nMedia: %.2f\n", (float)somma / n_esami);
}
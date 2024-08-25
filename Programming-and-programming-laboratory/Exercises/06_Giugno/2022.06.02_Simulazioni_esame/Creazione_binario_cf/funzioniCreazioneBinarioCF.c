#include <stdio.h>
#include <stdlib.h>

#include "funzioniCreazioneBinarioCF.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Persona p)
{
    Nodo *nuovaTesta = (Nodo *)malloc(sizeof(Nodo));
    nuovaTesta->dati = p;
    nuovaTesta->next = *pl;
    *pl = nuovaTesta;
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s %d %s\n", l->dati.codiceFiscale, l->dati.eta, l->dati.nome);
        l = l->next;
    }
    puts("");
}

void elimTesta(Lista *pl)
{
    Nodo *aux = (*pl);
    (*pl) = (*pl)->next;
    free(aux);
}

void scriviSuFile(char *nome, int eta, char *codiceFiscale, FILE *f)
{
    fwrite(nome, sizeof(nome), 1, f);
    fwrite(&eta, sizeof(nome), 1, f);
    fwrite(codiceFiscale, sizeof(nome), 1, f);
}
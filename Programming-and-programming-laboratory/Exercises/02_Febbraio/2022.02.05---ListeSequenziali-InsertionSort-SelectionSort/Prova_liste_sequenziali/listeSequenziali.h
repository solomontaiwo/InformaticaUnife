#include <stdio.h>
#include <stdlib.h>
#define DIMENSIONE 100

typedef struct
{
    int n_elementi;
    int dati[DIMENSIONE];
} Lista;

// azioni eseguibili con lista

void listaNuova(Lista *pl);
int vuota(Lista l);
int piena(Lista l);
void insTesta(Lista *pl, int elemento);
void insOrd(Lista *pl, int elemento);
void ricerca(Lista l, int elemento);
void elim1(Lista *pl, int elemento);
void elimTutti(Lista *pl, int numero);
int lunghezza(Lista l);
void stampa(Lista l);
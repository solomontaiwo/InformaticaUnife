#include <stdio.h>
#include <stdlib.h>
#define DIMENSIONE 100

typedef struct {
    int n_elementi;
    int dati[DIMENSIONE];
} Lista;

void nuova_lista(Lista *pl);
int vuota(Lista l);
int piena(Lista l);
void insTesta(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
int ricerca(Lista l, int numero);
void elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);
int lunghezza(Lista l);
void stampa(Lista l);
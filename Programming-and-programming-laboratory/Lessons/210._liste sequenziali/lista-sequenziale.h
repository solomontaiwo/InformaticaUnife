#include <stdio.h>
#include <stdlib.h>
#define DIMENSIONE 100

typedef struct
{
    int n_elementi; // dimensione logica
    int dati[DIMENSIONE];
} Lista;

void nuova_lista(Lista *pl);
int vuota(Lista 1);
int piena(Lista 1);
void insTesta(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
int ricerca(Lista l, int numero);
void elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);
int lunghezza(Lista 1);
void stampa(Lista 1);
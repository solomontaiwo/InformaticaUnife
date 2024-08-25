#include <stdlib.h>
#define DIM 5

typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
int vuota(Lista l);
int piena(Lista l);
void insTesta(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
int ricerca(Lista l, int numero);
void elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);
int lunghezza(Lista l);
void stampa(Lista l);

int vuota(Lista l)
{
    return l == NULL;
}

int piena(Lista l)
{
    return 0;
}

/* typedef struct
{
    int n_elementi;
    int dato[DIM];
} Lista;


void insTesta(Lista *pl, int numero)
{
    int i = pl->n_elementi;
    while (i > 0 && pl->dato[i - 1] > numero)
    {
        pl->dato[i] = pl->dato[i - 1];
        i--;
    }
    pl->dato[i] = numero;
    pl->n_elementi++;
}
*/
typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

int vuota(Lista l);
int piena(Lista l);
void inizializza(Lista *pl);
int ricerca(Lista *Pl, int numero);
void insTesta(Lista *pl, int numero);
void insCoda(Lista *pl, int numero);
Lista *ricercaCoda(Lista *pl);
Lista *ricercaElim1(Lista *pl, int numero);
Lista *ricercaOrdinato(Lista *pl, int numero);
void elim1(Lista *pl, int numero);
void elimTesta(Lista *pl);
void elimTutti(Lista *pl, int numero);
void stampa(Lista l);
void insertionSort(Lista *pl1);

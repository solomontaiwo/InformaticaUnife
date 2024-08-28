typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

int vuota(Lista l);
int piena(Lista l);
void stampa(Lista l);
int lunghezza(Lista l);
void inizializza(Lista *pl);
void listaNonOrdinata(Lista *pl, int numeroElementi);
void insTesta(Lista *pl, Dato d);
void insOrd(Lista *pl, Dato d);
void insertionSort(Lista *pl1);
void insCoda(Lista *pl, Dato d);
Lista *ricerca(Lista *pl, Dato d);
Lista *ricercaInsOrd(Lista *pl, Dato d);
Lista *ricercaInsTesta(Lista *pl);
Lista *ricercaInsCoda(Lista *pl);
int elim1(Lista *pl, Dato d);
void elimTutti(Lista *pl, Dato d);
void elimTesta(Lista *pl);
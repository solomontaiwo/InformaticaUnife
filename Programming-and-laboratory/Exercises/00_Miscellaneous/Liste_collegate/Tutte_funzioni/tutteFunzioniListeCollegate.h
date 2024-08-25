typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

int vuota(Lista l);
int piena(Lista l);
int lunghezza(Lista l);
void nuovaLista(Lista *pl);
void stampa(Lista l);
void listaNonOrdinata(Lista *pl, int numeroElementi);
Lista *ricerca(Lista *pl, Dato d);
Lista *ricercaInsOrd(Lista *pl, Dato d);
Lista *ricercaInsCoda(Lista *pl, Dato d);
void insTesta(Lista *pl, Dato d);
void insCoda(Lista *pl, Dato d);
void insOrd(Lista *pl, Dato d);
int elim1(Lista *pl, Dato d);
void elimTutti(Lista *pl, Dato d);
void elimTesta(Lista *pl);